#ifndef MYSCENE_H
#define MYSCENE_H


#include "mytextitem.h"
#include "mytypes.h"

class QGraphicsSceneMouseEvent;
class QGraphicsSceneContextMenuEvent;
class QUndoStack;
class QMenu;
class QAction;
#include <QGraphicsScene>

using namespace VPrn;

class myScene : public QGraphicsScene
{
    Q_OBJECT
public:

    myScene(QObject *parent = 0 );
    myScene(int Number = 99,QUndoStack* undoStack = 0, QObject *parent = 0 );

    /**
      * @brief создает на сцене страницу с размерами
      */
    void  createPage(qreal width,qreal height,qreal m_top,qreal m_bottom,
                     qreal m_right,qreal m_left);

    void  createPageForPrint(qreal width,qreal height);
    /**
      * @fn   QGraphicsItem * getPaperItem();
      * @brief Ищет на текущей странице элемент имеющий тег Paper и возвращает
      * указатель на него
      */
    QGraphicsItem * getPaperItem();

    QUndoStack *undoStack() const;

    void  setAngle(qreal Angle) {m_angle = Angle;}
    void  setViewMode();
    qreal getAngle(){return m_angle;}
    int   getNumber(){return m_Number;}
    bool  getViewMode(){return m_mode;}
protected:

    void  mouseReleaseEvent( QGraphicsSceneMouseEvent* );      // receive mouse release events
    void  contextMenuEvent( QGraphicsSceneContextMenuEvent* ); // receive context menu events
//    void  drawForeground  ( QPainter * painter, const QRectF & rect );

signals:
    void  message( QString );                   // info text message signal

public slots:
    void selectItems();     // records selected Item & positions

    /**
      * @fn addBaseElem(const QString &tag = QString("[XXX]"),const QString &text=QString(),
      *                 const QPointF &ps  = QPointF(100.0,100.0),
      *                 const QFont   &fnt = QFont("Times", 14, QFont::Bold),
      *                 const QColor  &col = Qt::black);
      *
      * @brief  Создает новый элемент TextItem и размещает его на текущей сцене
      */

    void addBaseElem(const QString &tag = QString("[XXX]"),const QString &text=QString(),
                     const QPointF &ps  = QPointF(100.0,100.0),
                     const QFont   &fnt = QFont("Times", 14, QFont::Bold),
                     const QColor  &col = Qt::black,
                     const qreal   m_angle = 0);
    void AddImgElement(const QString & file_name);

    void addImgElem(const QPointF &ps     = QPointF(100.0,100.0),
                    const qreal   m_angle = 0.0,
                    const qreal   m_scaled  = 0.0,
                    const QPixmap &img = QPixmap() );
private:
    /**
      * @var bool m_mode Режим показа элементов Тэг/Значение
      */
    bool m_mode;
    qreal m_angle;
    QUndoStack*      m_undoStack;        // undo stack for undo & redo of commands
    int m_Number;                        // При создании сцены она получает номер от 0 до 8

    typedef QPair<myTextItem*,QPointF>     ItemPos;
    QList<ItemPos>   m_TextItems;        // currently selected textitem & start positions



    //Меню для элементов
    QAction *changeFontAction;
    QAction *changeColorAction;
    QAction *rotateRightAction;
    QAction *rotateLeftAction;
    QAction *setTagAction;
    QAction *delElemAction;
};

#endif // MYSCENE_H
