#include "myrect.h"
#include <QGraphicsSceneMouseEvent>
MyRect::MyRect(int x, int y, int w, int h, int type)
{
    setAcceptHoverEvents(true);
    this->m_nX = x;
    this->m_nY = y;
    this->m_nW = w;
    this->m_nH = h;
    this->m_nType = type;
}

void MyRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::blue, 2));
    painter->setBrush(QBrush(Qt::SolidPattern));
    painter->setBrush(QColor(0, 0, 255));
    painter->drawRect(m_nX, m_nY, m_nW, m_nH);
}
QRectF MyRect::boundingRect()const{
    return QRectF(m_nX, m_nY, m_nW, m_nH);
}
void MyRect::mousePressEvent(QGraphicsSceneMouseEvent* event){

    if(this->m_nType == CHINESE_HALL){
        QMessageBox::information(nullptr, "Chinese Hall", "Name: Chinese Hall\n"
                                                          "Suggested Tour Time：60min\n"
                                                          "Restaurant: Yes");
    }else if(this->m_nType == BOTANICAL_HALL){
        QMessageBox::information(nullptr, "Botanical Hall", "Name: Botanical Hall\n"
                                                            "Suggested Tour Time: 30min\n"
                                                            "Restaurant: No");
    }else if(this->m_nType == GARDENING_TOWN){
        QMessageBox::information(nullptr, "Gardening Town", "Name: Gardening Town\n"
                                                            "Suggested Tour Time: 25min\n"
                                                            "Restaurant: No");
    }else if(this->m_nType == YONGNING_PAVILION){
        QMessageBox::information(nullptr, "Yongning Pavilion", "Name: Yongning Pavilion\n"
                                                               "Suggested Tour Time: 40min\n"
                                                               "Restaurant: No");
    }else if(this->m_nType == GUIRUI_THEATRE){
        QMessageBox::information(nullptr, "Guirui Theatre", "Name: Guirui Theatre\n"
                                                            "Suggested Tour Time: 30min\n"
                                                            "Restaurant: No");
    }else if(this->m_nType == INTERNATIONAL_HALL){
        QMessageBox::information(nullptr, "International Hall", "Name: International Hall\n"
                                                                "Suggested Tour Time: 80min\n"
                                                                "Restaurant: Yes");
    }else if(this->m_nType == LIFE_EXPERIENCE_HALL){
        QMessageBox::information(nullptr, "Life Experience Hall", "Name: Life Experience Hall\n"
                                                                  "Suggested Tour Time: 50min\n"
                                                                  "Restaurant: Yes");

    }
}
void MyRect::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    this->setCursor(QCursor(Qt::PointingHandCursor));
    QGraphicsItem::hoverEnterEvent(event);
}
void MyRect::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    this->setCursor(QCursor(Qt::ArrowCursor));
    QGraphicsItem::hoverLeaveEvent(event);
}
