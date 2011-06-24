#ifndef MY_TYPES_H
#define MY_TYPES_H

#include <QtCore/QMetaType>
#include <QtCore/QMap>
#include <QtGui/QPixmap>


namespace VPrn{

#define MY_DEBUG
#define POINT_TO_CM(cm) ((cm)/28.3465058)
#define POINT_TO_MM(mm) ((mm)/2.83465058)     ////////////  0.352777778
#define POINT_TO_DM(dm) ((dm)/283.465058)
#define POINT_TO_INCH(inch) ((inch)/72.0)

#define MM_TO_POINT(mm) ((mm)*2.83465058)
#define CM_TO_POINT(cm) ((cm)*28.3465058)     /////// 28.346456693
#define DM_TO_POINT(dm) ((dm)*283.465058)
#define INCH_TO_POINT(inch) ((inch)*72.0)

    /// @todo  Хардкодим по маленьку
    static const qint32 m_MaxInt32= 2147483647;

    typedef qint32 PACKET_SIZE ; // Максимальный размер пакета

    typedef QMap <int,QPixmap> PixmapList;
    typedef QMap <int,QString> PixmapDescList;

    static const int ObjectName = 0;
    static const int ObjectData = 1;
    static const int format = 13;

    static const char PARTSEPARATOR = ':';
    static const char MESSAGESEPARATOR = '|';

    struct Printers {
        QString name;       //Имя принтера (для пользователя)
        QString ip;         //IP адрес сервера где размещен принтер
        QString p_qqueue;   //Имя очереди печати (имя принтера в CUPS)
    };

    typedef QList<Printers> PrinterList;

    enum EventLogMessageId{
        //ErrorMessages
        eId_EmptyMessage      = 0,
        eId_AppsError         = 10,    // Внутрення ошибка приложения
        eId_FileNotFound      = 1000,
        eId_RecivedPacketSize = 2000,
        eId_SocketErrorDesc   = 2001,
        eId_CanNotBindPort    = 2003,
        eId_CanNotReadConfig  = 2004,
        eId_BrokenConfigFile  = 2005,
        eId_ServiceNotStarted = 2006,
        eId_NetworkError      = 2007,
        eId_SQL_CoreNotInited = 2008,
        //Information Messages        
        eId_ServiceStarted    = 4000,
        eId_ServiceStoped     = 4001,
        eId_ServicePaused     = 4002,
        eId_ServiceResume     = 4003,
        eId_SQL_CoreInited    = 4004,
        // DebugMessages
        eId_DebugInfo = 7000
                    };

    enum EventLogType{
        Success = 0, Error, Warning, Information
              };

    enum EventLogCategory{
        eCatId_Empty       = 0x0,
        eCatId_Error       = 0x1,
        eCatId_Information = 0x2,
        eCatId_DebugInfo   = 0x3
                         };
    enum pSizeColumnOrder{
        pSize_id     = 0, /// ID
        pSize_page   = 1, /// размер листа
        pSize_code   = 2, /// Код
        pSize_width  = 3, /// Ширина (мм)
        pSize_height = 4  /// Высота (мм)
                   };

    enum metaInfoOrder{
        metaInfo_name,    /// имя шаблона
        metaInfo_fname,   /// file_name шаблона
        metaInfo_desc,    /// Описание шаблона;
        metaInfo_orient,  /// Ориентация (Книжная/Альбомная)
        metaInfo_ctime,   /// Время создания
        metaInfo_mtime,   /// Время изменения
        metaInfo_author,  /// Автор
        metaInfo_mtop,    /// Отступ сверху (мм)
        metaInfo_mbottom, /// Отступ снизу (мм)
        metaInfo_mleft,   /// Отступ слева (мм)
        metaInfo_mright,  /// Отступ справа (мм)
        metaInfo_p_width, /// Ширина страницы (мм)
        metaInfo_p_height /// Высота страницы (мм)
    };

    enum DocCardOrder{
        cards_ID              = 0,  /// ID
        cards_DOC_NAME        = 1,  /// Имя документа
        cards_STAMP           = 2,  /// Выбранный гриф секретности
        cards_MB_NUMBER       = 3,  /// Номер МБ
        cards_PUNKT           = 4,  /// Пункт
        cards_PAGE_COUNT      = 5,  /// Число страниц
        cards_COPY_COUNT      = 6,  /// Всего экз
        cards_CURRENT_COPY    = 7,  /// Текущий экз
        cards_SELECT_ALL_COPY = 8,  /// Признак выбор всех экз
        cards_TEMPLATE_NAME   = 9,  /// Имя файла шаблона
        cards_EXECUTOR        = 10, /// Исполнитель
        cards_PRINTMAN        = 11, /// Отпечатал
        cards_PHONE           = 12, /// Телефон
        cards_INV_NUMBER      = 13, /// Инв.номер
        cards_PRINT_DATE      = 14, /// Дата печати
        cards_RECIVER_1       = 15, /// Получатель_1
        cards_RECIVER_2       = 16, /// Получатель_2
        cards_RECIVER_3       = 17, /// Получатель_3
        cards_RECIVER_4       = 18, /// Получатель_4
        cards_RECIVER_5       = 19, /// Получатель_5
        cards_STATUS          = 20  /// Статус_Документа
                            };



    enum tInfoColumnOrder{
        tInfo_id     = 0,  ///ID
        tInfo_name   = 1,  ///Имя шаблона
        tInfo_desc   = 2,  ///Описание шаблона;
        tInfo_pageID = 3,  ///Ссылка на таблицу размеры страниц
        tInfo_angle  = 4,  ///Поворот (град.)
        tInfo_ctime  = 5,  ///Время создания
        tInfo_mtime  = 6,  ///Время изменения
        tInfo_author = 7, ///Автор
        tInfo_mtop   = 8, ///Отступ сверху (мм)
        tInfo_mbottom = 9,///Отступ снизу (мм)
        tInfo_mleft   = 10,///Отступ слева (мм)
        tInfo_mright  = 11, ///Отступ справа (мм)
        tInfo_p_width = 12,
        tInfo_p_height= 13
                    };

    enum pageDetailColumnOrder{
        PD_id         = 0,  /// ID
        PD_p_number   = 1,  /// Порядковый номер в шаблоне
        PD_p_name     = 2,   /// Имя страницы
        PD_p_visible  = 3   /// Видна страница да/нет 1/0
                    };

    enum elemColumnOrder{
        elem_id    = 0,  ///ID
        elem_text  = 1,  ///Текст отображаемый на экране и на принтере
        elem_tag   = 2,  ///Тэг с которым работает программа
        elem_pos_x = 3,  ///Позиция элемента на сцене х
        elem_pos_y = 4,  ///Позиция элемента на сцене у
        elem_color = 5,  ///Цвет шрифта
        elem_font  = 6,  ///Шрифт
        elem_angle = 7,  ///Угол поворота относиттельно сцены
        elem_border= 8,  /// исовать границу элемента, да/нет
        elem_img_data = 9, /// Если эемент картинка то тут будет записанны данные в виде бинарных данных
        elem_img_scaled =10, /// масштаб картинки
        elem_always_view = 11, /// Всегда отображаемый Да/нет
        elem_p_number    = 12,  /// Порядковый номер страницы 0-7 на которой виден элемент
        elem_text_img    = 13  /// Тип элемента текст или картинка(1/0)
                       };

    enum AppErrorType {
        NoError,
        FileNotFound,
        FileIOError,
        UnknownError,
        SqlDriverNotLoad,
        NotConnectedToDB,
        DBOpeningError,
        SQLQueryError,
        SQLCommonError,
        InternalAppError,
        AuthCommonError,
        NetworkError,
        PluginsNotLoad,
        SocketError,
        ConfigError,
        notDefainedMode,
        appNotStarted,
        TemplateNotLoad
    };

    enum pageNumbers {
        FirstPage        = 1,
        FirstPageN2      = 2,
        FirstPageN3      = 3,
        FirstPageN4      = 4,
        FirstPageN5      = 5,
        SecondPage       = 6,
        ThirdPage        = 7,
        FourthPage       = 8,
    };

    enum trayIcons {
        InfoType,
        WarnType,
        CritType
    };

    enum trayStatus {
        gk_Started,
        gk_UserAuthorized,
        gk_UserLogin,
        gk_DoPrintJob,
        gk_DoReportJob,
        gk_WarningState,
        gk_ErrorState
    };

    enum MyCheckPoints{
        /// Глобальные "отметки" имеют префикс glob_
        //glob_Init,
        glob_Error,
        /// Локальные  "отметки" имеют префикс loc_  Работают с QLocalSocket/QLocalServer
        loc_CantStartListen,      /// Не могу запустить локальный сервер, порт занят
        loc_Connected,            /// Присоедиен к локальному серверу
        loc_Disconnected,         /// Отсоденился от локального сервера
        loc_ServerNotFound,       /// Локальный сервер не найден
        loc_ServerStart,          /// Локальный сервер запущен
        loc_LocalServerReady,     /// Локальный сервер готов к работе (Есть имя и мандат)
        loc_LocalServerNeedMandat,/// Локальный сервер готов к работе,(Есть имя но нет Мандата)
        loc_NewClientStarted,     /// К локальному серверу подключился новый клиент
        loc_MessageRecive,        /// Полученно сообщение в локальный сокет (в клиенте или в сервере)
        loc_NeedShutdown,         /// Отключился последний клиент, завершим работу
        /// Сетевые    "отметки" имеют префикс net_ Работают с QTcpSocket/QTcpServer
        net_HostNotFound,         /// Удаленный сервер не найден
        net_Connected,            /// Соединен с удаленным сервером
        net_Disconnected,         /// Отсодинен от удаленного сервера
        net_CommonError           /// Ошибка сети
    };

    enum Jobs{ /// Задания (работы)
        job_ConvertPs2Pdf,        /// Задача конвертирования ps в pdf
        job_ConvertPdf2Ps,        /// Задача конвертирования pdf в ps
        job_CalcPageCount,        /// Задача подсчета страниц в pdf файле
        job_SplitPageFirst,       /// Разбиение документа на первую стр.
        job_SplitPageOther,       /// Разбиение документа на последующие стр.
        job_MergePdf,             /// Объединение двух pdf в один
        job_PrintFile,            /// Печать документа на принтер
        job_ConvertToPng,         /// Преобразование в png исходного файла
        job_CatPages              /// Объединение двух pdf файлов в один
    };

    enum MessageType {
        ///Глобальные сообщения (для передачи/приема с мишиным Демоном)
        Que_RegisterGlobal     = 10,    /// Запрос на регистрацию клиента у Миши
        Ans_RegisterGlobal     = 1010,  /// Клиент зарегистрирован

        Que_AUTHOR_USER        = 100,   /// Запрос на авторизация пользователя к ресурсу П ИНТЕ
        Ans_PRINT_ALLOWED      = 1100,  /// печать разрешена
        Ans_PRINT_DENIED       = 1101,  /// печать запрещена
        Ans_PRINTER_NOT_FOUND  = 1102,  /// принтер не найден

        /**
          * @short  Запрос списка МБ за период:
          * В теле запроса заданы следующие параметры:
          * @param u_name;       Логин пользователя  \
                                                      ->Необходимы для авторизации на роль
          * @param u_mandat;     Мандат пользователя /
          * @param begin_period; Начало периода
          * @param end_period;   Конец периода
          * @param printer;      Принтер, конкретный или все
          */
        Que_GET_MB_LISTS       = 200,
        /**
          * @short  Демон вернул список, в формате (Дата в формате time_t)
          * Дата;:;МБ;:;номер_экз.;:;Название_документа;:;число страниц;:;статус
          */
        Ans_MB_LIST           = 1200,

        Que_SEC_LEVEL          = 300,   ///запрос к демону на получение списка уровней секретности
        Ans_STAMP_LIST         = 1300,  /// Список названий уровней секретности

        Que_GET_PRINTER_LIST   = 400,   /// Запрос списка принтеров
        Ans_PRINTER_LIST       = 1400,  /// Ответ список принтеров
        Ans_PRINTER_LIST_EMPTY = 1401,  /// Список принтеров пуст !

        /**
          * @short  Запрос есть ли в базе документ:  заданным МБ и номером экз
          *  в теле сообщения содержиться sql запрос к базе данных
          */
        Que_IS_MB_EXIST           = 500,
        Ans_MB_NOT_EXIST          = 1500, /// Документ в базе не был зарегистрирован
        /**
          *@short Документ в БД зарегистрирован, помечен как брак, запустип
          * дополнительную проверку на совпадение остальных полей
          */
        Ans_MB_EXIST_AND_BRAK     = 1505,
        /**
          *@short Документ в БД зарегистрирован, помечен как распечатан, запустип
          * дополнительную проверку на совпадение остальных полей
          */
        Ans_MB_EXIST_AND_NOT_BRAK = 1510,

        /**
          * @short Регистрация документа в БД учета
          *  в теле сообщения содержиться sql запрос к базе данных
          */
        Que_RegisterDocInBase     = 570,

        Ans_RegisterDocInBase     = 1570, /// Регистрация в БД учета завершена

        Que_MANDAT_LIST        = 600,
        Ans_MANDAT_LIST        = 1600,  /// Список мандатов к которым допущен пользоватль
        Ans_MANDAT_LIST_EMPTY  = 1601,  /// У данного пользователя нет ни одного мадата

        /**
          * @short Запрос свободного места на сервере печати
          *  в теле сообщения содержиться QUIN64
          */
        Ans_GetFreeSpace       = 1700,
        Que_NotFreeSpace       = 1710,
        Que_AllocFreeSpace     = 1720,

        /// Локальные сообщения (для обмена с моим сервисом)
        Que_Register           = 5010,  /// Запрос на регистрацию
        Ans_Register           = 5015,  /// Ответ о регистрации

        Que_ServerStatus       = 5020,  /// Запрос у сервера его состояния
        Ans_SrvStatusNotReady  = 5025,  /// Ответ сервера.Не готов к работе Подробности в теле сообщения
        Ans_SrvStatusPartReady = 5026,  /// Ответ сервера.Готов к работе (Есть login пользователя,нет мандата, есть связь с демоном)
        Ans_SrvStatusFullReady = 5027,  /// Ответ сервера.Готов к работе (Есть auth данные пользователя, есть связь с демоном)

        Que_Convert2Pdf        = 5050,  /// Запрос на преобразование исходлного ps файла в pdf
        Ans_Convert2PdfFinish  = 5051,  /// После успешного преобразования сообщим об этом клиенту
        Ans_PageCounting       = 5052,  /// Вернем число страниц в документеPageCounting
        Ans_PageSplittedFirst  = 5053,  /// Разбиение документа на первую страницу завершено
        Ans_PageSplittedOther  = 5054,  /// Разбиение документа на последующую страницу завершено

        /**
          * @short  Запрос на формирование документа пред.В теле запроса:
          *   Данные относятся к плагину tmpl_sql_plugin
          * @li Полный путь к выбранному пользователем шаблону
          * @li Набор данных из полей ввода,
          */
        Que_CreateFormatedFullDoc  = 5100, /// Полный документ
        Que_CreateFormatedPartDoc  = 5110, /// Только его часть
        /// @short Полный документ для печати, в теле сообщения принтер, набор данных
        Que_CreateFormatedFullDocAndPrint = 5200,  /// Сообщение уходит в сеть к демону

        /// @short Ans_TemplateNotFound  - Шаблон не найден или поврежден, в теле сообщения подробности
        Ans_TemplateNotFound   = 5101,
        /// @short Ans_SourceDocNotFound - Исходный документ не найден или не верного формата, в теле сообщения подробности
        Ans_SourceDocNotFound  = 5102,

        /// @short Ans_CreateFormatedDoc - На документ успешно наложен шаблон
        Ans_CreateFormatedDoc  = 5103,

        /** @short Ans_ConvertFormatedDocToPng - Документ успешно конвертирован в png,
          * в теле сообщения:
            * @li Кол-во файлов
            * @li список путей к файлам изображений стр.
          */
        Ans_ConvertFormatedDocToPng  = 5104,

        /**
          * @short Печать текущего документа,юзер посмотрел его превюшку и нажал на кнопку печать
          * В теле сообщения указан выбранный пользователем принтер
          */
        Que_PrintCurrentFormatedDoc = 5210,
        Ans_PrintFormatedDoc        = 5201,  /// Документ распечатан, ответ от демона
        Ans_PrintFormatedDoc_Error  = 5202,  /// Документ не распечатан, ответ от демона подробности в теле

        /** @short  Запрос на загрузку шаблонов и получение их метаинформации,
          * в теле запроса, QStringList содержащий список шаблоно которые надо загрузить
          */
        Que_GiveMeTemplatesList     = 5300,
        /** @short Ответ содержит QStandardItemModel преобразованный в QByteArray
          * с помощью класса @sa @class TemplatesInfo
          */
        Ans_GiveMeTemplatesList     = 5310,

        /**
          *@brief Запрос на перезапуск процесса работы, в теле сообщения,
          * сохранен номер МБ и номер экземпляра, для пометки их как брак
          */
        Que_UserDemands2Restart      = 5500,

        /*
         * @short Que_PrintThisFile Печать файла на выбранный пользователем принтер
         * @param (QString) JobID (уникально для каждого экз. документа)
         * @param (QString) Имя принтера (очереди печати на CUPS)
         * @param (qint8)   copy_number  число копий 1-100
         * @param (QString) user_name    имя пользователя
         * @param (QString) job_title    имя задания
         * @param (qint64) array_size   размер не сжатого буфера
         * @param (QByteArray) файл для печати в формате QByteArray (сжатый)
        */
        Que_PrintThisFile            = 6000,
        Ans_PrintThisFileSuccess     = 6010,
        Ans_PrintThisFileFailure     = 6020,

        /*
         * @short Que_ReciveFile отправка файла демону для дальнейшей печати
         * @param QString      Уникальный индетификатор отправляемого файла
         * @param qint32       Размер не сжатого файла (max qint32) byte
         * @param QByteArray   Файл для печати в формате QByteArray (сжатый)
         */
        Que_ReciveFile               = 6030,
        Ans_ReciveFileSuccess        = 6031,
        Ans_ReciveFileFailure        = 6032,


        /**
          * @short Que_CheckFileSize Запрос у мишиного демона, может ли он принять файл
          * @param (qint64) array_size   размер не сжатого буфера
          */
        Que_CheckFileSize            = 6060,
        Ans_CheckFileSizeSuccess     = 6065, // Ответ может
        Ans_CheckFileSizeFailure     = 6070, // Ответ нет не может

        /*
         * @short Запрос/ответ пользователь должен пометить экз документа как ЧИСТОВИК/БРАК
         * @param (QString) Название документа
         * @param (QString) Принтер на котором печатался документ
         * @param (QString) МБ номер документа
         * @param (qint8)   Номер экземпляра
         * ----------------------------------------------------------
         *
         */
        Que_UserNeedMarkCopies       = 6100,
        Ans_UserNeedMarkCopies       = 6110,
        SaveToBaseCopiesMarker       = 6120,
        /// Запрос пользователю на переворот страниц
        Que_UserNeedFlipPages        = 6150,
        /// Запрос пользователю проверь что лежит последняя страница документа
        /// обратной стороной для печати фонарика
        Que_UserNeedCheckLastPage    = 6170,
        /// Информационное сообщение начата печать i-го экз. документа
        Que_BeginPrintCopies         = 6200,

        ///Сообщения от консольных клиентов
        SaveUserToBase   = 8000,
        ///Служебные сообщения
        GoodBay          = 70000,        /// GateKeeper завершает работу и Вам пора
        Err_Message      = 70010,        /// Сообщение об ошибке.Подробности в теле сообщения
        NoMsgType        = 0
                       };

    enum {
        Page_Intro     = 0,
        Page_Select    = 1,          
        Page_PrintData = 2,
        Page_CheckData = 3,
        Page_Preview   = 4,
        Page_Finish    = 5,
        Page_SetBrak   = 6
                     };

    /**
     * @brief  Режимы предпросмотра при печати
     * @li  FullPreviewMode  Просмотр всех страниц всех экз.
     * @li  PartPreviewMode Просмотр только ключевых страниц (1-х страниц) каждого экз.
     * @li  PrintWithoutPreviewMode  Печать без просмотра
     */
    enum PreviewMode{
        pre_FullMode       = 0,
        pre_PartMode       = 1,
        pre_ClearPrintMode = 2
                         };


}

Q_DECLARE_METATYPE(VPrn::AppErrorType);
Q_DECLARE_METATYPE(VPrn::PreviewMode);
Q_DECLARE_METATYPE(VPrn::Jobs);
Q_DECLARE_METATYPE(VPrn::MyCheckPoints);
Q_DECLARE_METATYPE(VPrn::DocCardOrder);
Q_DECLARE_METATYPE(VPrn::MessageType);
Q_DECLARE_METATYPE(VPrn::trayIcons);
Q_DECLARE_METATYPE(VPrn::trayStatus);
Q_DECLARE_METATYPE(VPrn::pSizeColumnOrder);
Q_DECLARE_METATYPE(VPrn::tInfoColumnOrder);
Q_DECLARE_METATYPE(VPrn::elemColumnOrder);
Q_DECLARE_METATYPE(VPrn::pageDetailColumnOrder);
Q_DECLARE_METATYPE(VPrn::pageNumbers);
#endif

