#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Liquid Calculator");
    Liquid::set_nicotine_strength(20);
    ui->mg_per_ml_input->setValue(20);
    // set up tool tips
    ui->mg_per_ml_input->setToolTip("Dosage of your Nicotine Base?");
    ui->aroma_input->setToolTip("Total Percentage of Flavour in finished Liquid?");
    ui->total_input->setToolTip("How many ml of Liquid dou you want to prepare?");
    ui->nicotin_input->setToolTip("What dosage of nicotine do you want in the finished Liquid?");
    // connecting
    connect(ui->calc_button, SIGNAL(clicked()), this, SLOT(slot_calculate_new()));
    connect(ui->mg_per_ml_input, SIGNAL(valueChanged(int)), this, SLOT(slot_set_static_dose(int)));

}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::slot_calculate_new() {
    double _vol_total = ui->total_input->value();
    double _percent_aroma = ui->aroma_input->value();
    double _nic_mg_per_ml = ui->nicotin_input->value();
    if (! (_percent_aroma >= 0) && (_vol_total>0) ) {
        ui->error_label->setText("Invalid Input - Please try again!");
        return;
    }
    Liquid *l = new Liquid(_vol_total, _percent_aroma, _nic_mg_per_ml);
    ui->nicotine_output->setText(QString::number(l->get_nicotine()));
    ui->base_output->setText(QString::number(l->get_base()));
    ui->aroma_output->setText(QString::number(l->get_aroma()));
    delete l;
}


void MainWindow::slot_set_static_dose(int i) {
    if (! (i>0)){
        ui->error_label->setText("Invalid Input - Please try again!");
        return;
    }
    Liquid::set_nicotine_strength(i);
}

