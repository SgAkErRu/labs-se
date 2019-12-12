#ifndef PICTUREBOX_H
#define PICTUREBOX_H

#include <QFrame>
#include <QPainter> // для пейнт евента
#include <QMouseEvent>

using scanline = QVector<QPoint>;
using scanlines = QVector<scanline>;

class PictureBox : public QFrame
{
    Q_OBJECT
    QPixmap m_Pixmap; // для рисования
    QPixmap m_Grid; // сетка
    QPoint ToCenterCoordinateSystem(const int x, const int y) const;
    void DrawCircle(const int r, QPainter &painter); // нарисовать круг
    QVector<QPoint> vertex;
    scanlines arr_scanlines;
    void find_intersections();
    void fill();

public:
    explicit PictureBox(QWidget *parent = nullptr);
    void risovanie(); // функция рисования
    void DrawGrid(); // нарисовать сетку
    void mousePressEvent ( QMouseEvent * event );
    void DrawDirectLine(const QPoint q1, const QPoint q2, QColor color, QPainter &painter);
protected:
    virtual void paintEvent(QPaintEvent*); // функция перерисовки, отрисовывает готовый пиксмап из ф-ции risovanie
};
#endif // PICTUREBOX_H

