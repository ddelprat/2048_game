#ifndef GRIDMODEL_H
#define GRIDMODEL_H
#pragma once

#include <QAbstractListModel>

class GridModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit GridModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

};

#endif
