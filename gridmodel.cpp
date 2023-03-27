#include "GridModel.h"

GridModel::GridModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int GridModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 16; // 16 cases dans la grille (4x4)
}

QVariant GridModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return index.row() + 1; // afficher un nombre unique dans chaque case
    }
    return QVariant();
}
