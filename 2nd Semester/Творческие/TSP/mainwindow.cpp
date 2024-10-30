#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QThread>
#include <QTimer>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>

#include "Graph.h"
#include "TSP.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



QGraphicsScene* MainWindow::CreateScene()
{
    int R = 200;
    int ell_r = 50;
    double pi = 3.14;

    QGraphicsScene* new_Scene = new QGraphicsScene;

    int ver_c = 0;
    for(auto ver : G.Smatr)
    {
        double angle_s = ((2 * pi) / G.Smatr.size()) * (ver_c);
        for(unsigned int j = 0; j < ver.size(); j++)
        {
            if(ver[j])
            {
                double angle_f = ((2 * pi) / G.Smatr.size()) * j;
                QGraphicsLineItem *edge = new_Scene->addLine(R*std::cos(angle_s), R*std::sin(angle_s), R*std::cos(angle_f), R*std::sin(angle_f));
                QPen PenEdge(Qt::black);
                edge->setPen(PenEdge);
            }
        }
        ver_c += 1;
    }

    ver_c = 0;
    for(auto ver : G.Smatr)
    {
        double angle_s = ((2 * pi) / G.Smatr.size()) * (ver_c);
        for(unsigned int j = 0; j < ver.size(); j++)
        {
            if(ver[j])
            {
                double angle_f = ((2 * pi) / G.Smatr.size()) * j;
                QGraphicsTextItem *text = new_Scene->addText(QString::number(ver[j]));
                text->setDefaultTextColor(Qt::black);
                text->setHtml(QString("<div style='background:rgba(255, 255, 255, 0);'>" + QString::number(ver[j]) + QString("</div>")));
                text->setFont(QFont("Arial", 12));
                QPointF textPos = QPointF(R*std::cos(angle_s) + (R*std::cos(angle_f) -  R*std::cos(angle_s)) / 2 - 3, R*std::sin(angle_s) + (R*std::sin(angle_f) -  R*std::sin(angle_s)) / 2);
                text->setPos(textPos);
            }
        }
        ver_c += 1;
    }

    for(unsigned int i = 0; i < G.Smatr.size(); i++)
    {
        double angle = ((2 * pi) / G.Smatr.size()) * i;
        QGraphicsEllipseItem *ELL = new_Scene->addEllipse(R*std::cos(angle) - ell_r/2, R*std::sin(angle) - ell_r/2, ell_r, ell_r);
        QPen penELL(Qt::black);
        QBrush brushELL(Qt::yellow);
        ELL->setPen(penELL);
        ELL->setBrush(brushELL);

        QGraphicsTextItem *text = new_Scene->addText(/*QString::number(i+1)*/ VerNames[i]);
        text->setDefaultTextColor(Qt::black);
        text->setFont(QFont("Arial", 14));
        text->setPos(R*std::cos(angle)-10, R*std::sin(angle)-14);
    }

    return new_Scene;
}


QGraphicsScene* MainWindow::CreateTSPScene(int TSPcur)
{
    int R = 200;
    int ell_r = 50;
    double pi = 3.14;

    QGraphicsScene* new_Scene = new QGraphicsScene;

    int ver_c = 0;
    for(auto ver : G.Smatr)
    {
        double angle_s = ((2 * pi) / G.Smatr.size()) * (ver_c);
        for(unsigned int j = 0; j < ver.size(); j++)
        {
            if(ver[j])
            {
                double angle_f = ((2 * pi) / G.Smatr.size()) * j;
                QGraphicsLineItem *edge = new_Scene->addLine(R*std::cos(angle_s), R*std::sin(angle_s), R*std::cos(angle_f), R*std::sin(angle_f));
                QPen PenEdge(Qt::black);
                edge->setPen(PenEdge);
            }
        }
        ver_c += 1;
    }

    ver_c = 0;
    for(auto ver : G.Smatr)
    {
        double angle_s = ((2 * pi) / G.Smatr.size()) * (ver_c);
        for(unsigned int j = 0; j < ver.size(); j++)
        {
            if(ver[j])
            {
                double angle_f = ((2 * pi) / G.Smatr.size()) * j;
                QGraphicsTextItem *text = new_Scene->addText(QString::number(ver[j]));
                text->setDefaultTextColor(Qt::black);
                text->setHtml(QString("<div style='background:rgba(200, 200, 200, 0);'>" + QString::number(ver[j]) + QString("</div>")));
                text->setFont(QFont("Arial", 12));
                QPointF textPos = QPointF(R*std::cos(angle_s) + (R*std::cos(angle_f) -  R*std::cos(angle_s)) / 2 - 3, R*std::sin(angle_s) + (R*std::sin(angle_f) -  R*std::sin(angle_s)) / 2);
                text->setPos(textPos);
            }
        }
        ver_c += 1;
    }

    for(unsigned int i = 0; i < G.Smatr.size(); i++)
    {
        double angle = ((2 * pi) / G.Smatr.size()) * i;
        QGraphicsEllipseItem *ELL = new_Scene->addEllipse(R*std::cos(angle) - ell_r/2, R*std::sin(angle) - ell_r/2, ell_r, ell_r);
        QPen penELL(Qt::black);
        QBrush brushELL(Qt::yellow);
        if(i == TSPcur)
        {
            brushELL.setColor(Qt::gray);
        }
        ELL->setPen(penELL);
        ELL->setBrush(brushELL);

        QGraphicsTextItem *text = new_Scene->addText(/*QString::number(i+1)*/ VerNames[i]);
        text->setDefaultTextColor(Qt::black);
        text->setFont(QFont("Arial", 14));
        text->setPos(R*std::cos(angle)-10, R*std::sin(angle)-14);
    }

    return new_Scene;
}

void MainWindow::TSPdrawer(std::vector<int> path, int cur_i)
{
    if(cur_i >= path.size())
    {
        return;
    }
    else
    {
        //QGraphicsScene *prev_scene = ui->graphicsView->scene();
        QGraphicsScene *new_Scene = CreateTSPScene(path[cur_i]);
        ui->graphicsView->setScene(new_Scene);
        //if(prev_scene) delete prev_scene;

        QTimer timer;
        timer.setInterval(800); // 1 секунда
        bool timerExpired = false;
        QObject::connect(&timer, &QTimer::timeout, [&timerExpired]() {
         timerExpired = true;
        });
        timer.start();
        while (!timerExpired) {
        QCoreApplication::processEvents();
        }
        timer.stop();
        TSPdrawer(path, cur_i + 1);
        return;
        }
    return;
}




void MainWindow::on_add_ver_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString VerName = ui->add_ver_vername_textEdit->toPlainText();
    if(VerName == "")
    {
        ui->add_ver_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_ver_status_label->setText("не задано имя вершины");
        return;
    }
    VerNames.push_back(VerName);
    ui->add_ver_vername_textEdit->setText("");

    stringstream ss(ui->add_ver_textEdit->toPlainText().toStdString());
    ui->add_ver_textEdit->setText("");
    vector<int> vers; int a;
    while (ss >> a) {vers.push_back(a);}
    if(vers.size() == 0)
    {
        for(int i = 0; i < G.Smatr.size(); i++)
        {
            vers.push_back(0);
        }
    }
    if(vers.size() != G.Smatr.size())
    {
        ui->add_ver_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_ver_status_label->setText("неверное кол-во рёбер");
        return;
    }

    for (unsigned int i = 0; i < G.Smatr.size(); i++)
    {
        G.Smatr[i].push_back(vers[i]);
    }
    vers.push_back(0);
    G.Smatr.push_back(vers);

    ui->add_ver_status_label->setStyleSheet("QLabel {color : black;}");
    ui->add_ver_status_label->setText(QString("Вершин: ") + QString::number(G.Smatr.size()));

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_del_ver_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString VerName = ui->add_ver_vername_textEdit->toPlainText();
    ui->add_ver_vername_textEdit->setText("");

    if(VerName == "")
    {
        ui->add_ver_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_ver_status_label->setText("не задана вершина");
        return;
    }
    bool flag = false; int index = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(VerName == VerNames[i])
        {
            flag = true; index = i;
        }
    }

    if(flag)
    {
        for (unsigned int i = 0; i < G.Smatr.size(); i++)
        {
            auto it = G.Smatr[i].begin();
            advance(it, index);
            G.Smatr[i].erase(it);
        }
        auto it = G.Smatr.begin();
        advance(it, index);
        G.Smatr.erase(it);

        auto it_vn = VerNames.begin();
        advance(it_vn, index);
        VerNames.erase(it_vn);
    }
    else
    {
        ui->add_ver_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_ver_status_label->setText("неверная вершина");
        return;
    }

    ui->add_ver_status_label->setStyleSheet("QLabel {color : black;}");
    ui->add_ver_status_label->setText("");
    ui->add_ver_status_label->setText(QString("Вершин: ") + QString::number(G.Smatr.size()));

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_add_edge_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString from = ui->add_edge_f_textEdit->toPlainText();
    QString to = ui->add_edge_s_textEdit->toPlainText();
    QString ves = ui->add_edge_ves_textEdit->toPlainText();

    if(from == "" || to == "")
    {
        ui->add_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_edge_status_label->setText("неверные вершины");

        ui->add_edge_f_textEdit->setText("");
        ui->add_edge_s_textEdit->setText("");
        ui->add_edge_ves_textEdit->setText("");

        return;
    }
    if(from == to)
    {
        ui->add_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_edge_status_label->setText("неподходящее ребро");

        ui->add_edge_f_textEdit->setText("");
        ui->add_edge_s_textEdit->setText("");
        ui->add_edge_ves_textEdit->setText("");

        return;
    }
    if(ves == "")
    {
        ui->add_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_edge_status_label->setText("не задан вес ребра");

        ui->add_edge_f_textEdit->setText("");
        ui->add_edge_s_textEdit->setText("");
        ui->add_edge_ves_textEdit->setText("");

        return;
    }

    bool flag_f = false; bool flag_s = false; int index_f = -1; int index_s = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(from == VerNames[i])
        {
            flag_f = true; index_f = i;
        }
        else if(to == VerNames[i])
        {
            flag_s = true; index_s = i;
        }

    }

    if(flag_f && flag_s)
    {
        G.Smatr[index_f][index_s] = ves.toInt();
        G.Smatr[index_s][index_f] = ves.toInt();
    }
    else
    {
        ui->add_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_edge_status_label->setText("неверные вешины");
        ui->add_edge_f_textEdit->setText("");
        ui->add_edge_s_textEdit->setText("");
        ui->add_edge_ves_textEdit->setText("");

        return;
    }

    ui->add_edge_f_textEdit->setText("");
    ui->add_edge_s_textEdit->setText("");
    ui->add_edge_ves_textEdit->setText("");
    ui->add_edge_status_label->setStyleSheet("QLabel {color : black;}");
    ui->add_edge_status_label->setText("");


    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_del_edge_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString from = ui->add_edge_f_textEdit->toPlainText();
    QString to = ui->add_edge_s_textEdit->toPlainText();

    if(from == "" || to == "")
    {
        ui->add_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_edge_status_label->setText("неверные вершины");

        ui->add_edge_f_textEdit->setText("");
        ui->add_edge_s_textEdit->setText("");
        ui->add_edge_ves_textEdit->setText("");

        return;
    }
    if(from == to)
    {
        ui->add_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_edge_status_label->setText("неверное ребро");

        ui->add_edge_f_textEdit->setText("");
        ui->add_edge_s_textEdit->setText("");

        return;
    }

    bool flag_f = false; bool flag_s = false; int index_f = -1; int index_s = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(from == VerNames[i])
        {
            flag_f = true; index_f = i;
        }
        else if(to == VerNames[i])
        {
            flag_s = true; index_s = i;
        }

    }

    if(flag_f && flag_s)
    {
        G.Smatr[index_f][index_s] = 0;
        G.Smatr[index_s][index_f] = 0;
    }
    else
    {
        ui->add_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_edge_status_label->setText("неверные вешины");
        return;
    }

    ui->add_edge_f_textEdit->setText("");
    ui->add_edge_s_textEdit->setText("");
    ui->add_edge_status_label->setStyleSheet("QLabel {color : black;}");
    ui->add_edge_status_label->setText("");
    ui->add_edge_ves_textEdit->setText("");

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_BFS_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString start_ver = ui->BFS_textEdit->toPlainText();

    if(start_ver== "")
    {
        ui->BFS_status_label->setStyleSheet("QLabel {color : red;}");
        ui->BFS_status_label->setText("неверная вершина");
        ui->BFS_textEdit->setText("");
        ui->BFS_result_textBrowser->setText("");

        ui->BFS_textEdit->setText("");

        return;
    }

    bool flag = false; int index = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(start_ver == VerNames[i])
        {
            flag = true; index = i;
        }

    }

    if(flag)
    {
        QString RESULT = "";

        vector<bool> visited(G.Smatr.size(), false);
        queue<int> q;

        visited[index] = true;
        q.push(index);

        while(!q.empty())
        {
            int curVer = q.front();
            q.pop();

            RESULT += VerNames[curVer];
            RESULT += " ";

            for(int neighbor = 0; neighbor < G.Smatr.size(); neighbor++)
            {
                if(G.Smatr[curVer][neighbor] != 0 && !visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        ui->BFS_result_textBrowser->setText(RESULT);

    }
    else
    {
        ui->BFS_status_label->setStyleSheet("QLabel {color : red;}");
        ui->BFS_status_label->setText("неверная вешина");
        ui->BFS_textEdit->setText("");
        ui->BFS_result_textBrowser->setText("");

        return;
    }

    ui->BFS_textEdit->setText("");
    ui->BFS_status_label->setStyleSheet("QLabel {color : black;}");
    ui->BFS_status_label->setText("");

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_DFS_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString start_ver = ui->BFS_textEdit->toPlainText();

    if(start_ver== "")
    {
        ui->BFS_status_label->setStyleSheet("QLabel {color : red;}");
        ui->BFS_status_label->setText("неверная вершина");
        ui->BFS_textEdit->setText("");
        ui->BFS_result_textBrowser->setText("");

        ui->BFS_textEdit->setText("");

        return;
    }

    bool flag = false; int index = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(start_ver == VerNames[i])
        {
            flag = true; index = i;
        }

    }

    if(flag)
    {
        QString RESULT = "";

        vector<bool> visited(G.Smatr.size(), false);
        stack<int> s;

        visited[index];
        s.push(index);

        while(!s.empty())
        {
            int curVer = s.top();
            s.pop();

            if(!visited[curVer])
            {
                visited[curVer] = true;
                RESULT += VerNames[curVer];
                RESULT += " ";

                for(int neighbor = 0; neighbor < G.Smatr.size(); neighbor++)
                {
                    if(G.Smatr[curVer][neighbor] != 0 && !visited[neighbor])
                    {
                        s.push(neighbor);
                    }
                }
            }
        }

        ui->BFS_result_textBrowser->setText(RESULT);

    }
    else
    {
        ui->BFS_status_label->setStyleSheet("QLabel {color : red;}");
        ui->BFS_status_label->setText("неверная вешина");
        ui->BFS_textEdit->setText("");
        ui->BFS_result_textBrowser->setText("");

        return;
    }

    ui->BFS_textEdit->setText("");
    ui->BFS_status_label->setStyleSheet("QLabel {color : black;}");
    ui->BFS_status_label->setText("");

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_DA_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString start_ver = ui->BFS_textEdit->toPlainText();

    if(start_ver== "")
    {
        ui->BFS_status_label->setStyleSheet("QLabel {color : red;}");
        ui->BFS_status_label->setText("неверная вершина");
        ui->BFS_textEdit->setText("");
        ui->BFS_result_textBrowser->setText("");

        ui->BFS_textEdit->setText("");

        return;
    }

    bool flag = false; int index = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(start_ver == VerNames[i])
        {
            flag = true; index = i;
        }

    }

    if(flag)
    {

        int numVertices = G.Smatr.size();
        vector<bool> visited(numVertices, false);
        vector<int> distances;
        distances.resize(numVertices, std::numeric_limits<int>::max());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distances[index] = 0;
        pq.push(make_pair(0, index));

        while(!pq.empty())
        {
            int currentVertex = pq.top().second;
            pq.pop();


            if (visited[currentVertex])
            {
                continue;
            }

            visited[currentVertex] = true;

            for (int neighbor = 0; neighbor < numVertices; ++neighbor)
            {
                int weight = G.Smatr[currentVertex][neighbor];

                if (weight > 0)
                {
                    int distance = distances[currentVertex] + weight;

                    if (distance < distances[neighbor])
                    {
                        distances[neighbor] = distance;
                        pq.push(make_pair(distance, neighbor));
                    }
                }
            }
        }

        QString RESULT = "";
        for(int i = 0; i < numVertices; i++)
        {
            if(distances[i] == numeric_limits<int>::max())
            {
                RESULT += VerNames[i]; RESULT += ":"; RESULT += " inf"; RESULT += " ";
            }
            else
            {
                RESULT += VerNames[i]; RESULT += ": "; RESULT += QString::number(distances[i]); RESULT += " ";
            }
        }
        ui->BFS_result_textBrowser->setText(RESULT);

    }
    else
    {
        ui->BFS_status_label->setStyleSheet("QLabel {color : red;}");
        ui->BFS_status_label->setText("неверная вешина");
        ui->BFS_textEdit->setText("");
        ui->BFS_result_textBrowser->setText("");

        return;
    }

    ui->BFS_textEdit->setText("");
    ui->BFS_status_label->setStyleSheet("QLabel {color : black;}");
    ui->BFS_status_label->setText("");

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_example_graph_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    G.Smatr.clear();
    VerNames.clear();
    G.Smatr = {{0, 0, 0, 6, 7},
               {0, 0, 2, 0, 9},
               {0, 2, 0, 4, 8},
               {6, 0, 4, 0, 5},
               {7, 9, 8, 5, 0} };
    VerNames = {"A", "B", "C", "D", "E"};

    ui->add_ver_status_label->setText(QString("Вершин: ") + QString::number(G.Smatr.size()));

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_example_graph_delete_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    G.Smatr.clear();
    VerNames.clear();
    ui->add_ver_status_label->setText(QString("Вершин: ") + QString::number(G.Smatr.size()));

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_TSP_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString start_ver = ui->TSP_textEdit->toPlainText();

    if(start_ver== "")
    {
        ui->TSP_status_label->setStyleSheet("QLabel {color : red;}");
        ui->TSP_status_label->setText("неверная вершина");
        ui->TSP_textEdit->setText("");
        ui->TSP_result_textBrowser->setText("");

        ui->TSP_textEdit->setText("");

        return;
    }

    bool flag = false; int index = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(start_ver == VerNames[i])
        {
            flag = true; index = i;
        }

    }

    if(flag)
    {
        vector<string> verNames_std;
        int start = 0; int i = 0;
        for(auto qstr : VerNames)
        {
            verNames_std.push_back(qstr.toStdString());
            if(qstr == start_ver)
            {
                start = i;
            }
            i++;
        }

        TSPSolver tsp(G, start);
        tsp.solve(G);

        string path_std = tsp.getBestPath(verNames_std);
        if (path_std == "Нет решения") {
            ui->TSP_result_textBrowser->setText(QString::fromStdString(path_std));
        } else {
            string path_cost = "Длина маршрута: " + to_string(tsp.getBestCost());
            ui->TSP_result_textBrowser->setText(QString::fromStdString(path_std));
            ui->TSP_result_textBrowser_2->setText(QString::fromStdString(path_cost));

            std::vector<int> BestPath = tsp.bestpath_vec();

            TSPdrawer(BestPath, 0);

        }
        //ui->TSP_result_textBrowser->setText(QString::fromStdString(path_std));

    }
    else
    {
        ui->TSP_status_label->setStyleSheet("QLabel {color : red;}");
        ui->TSP_status_label->setText("неверная вешина");
        ui->TSP_textEdit->setText("");
        ui->TSP_result_textBrowser->setText("");

        return;
    }

    ui->TSP_textEdit->setText("");
    ui->TSP_status_label->setStyleSheet("QLabel {color : black;}");
    ui->TSP_status_label->setText("");



    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}

