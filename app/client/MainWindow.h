#ifndef METADATA_WINDOW_H_
#define METADATA_WINDOW_H_

#include "lib/unicorn/UnicornMainWindow.h"
#include "lib/unicorn/StylableWidget.h"
#include <lastfm/Track>
#include <lastfm/XmlQuery>

using lastfm::XmlQuery;

class QAbstractButton;
class QTabBar;
class QLabel;
class ScrobbleControls;
class FirstRunWizard;
class MessageBar;
class SlideOverLayout;
class UserToolButton;


class MainWindow : public unicorn::MainWindow
{
    Q_OBJECT

    struct{
        class TitleBar* titleBar;
        class StatusBar* statusBar;

        class SideBar* sideBar;
        class QStackedWidget* stackedWidget;

        QWidget* nowPlaying;
        class ActivityListWidget* recentTracks;
        QWidget* profile;
        QWidget* friends;
        class RadioWidget* radio;

    } ui;

public:
    MainWindow();
    const Track& currentTrack() const{ return m_currentTrack; }

    void addWinThumbBarButton( QAction* );

signals:
    void trackGotInfo(XmlQuery);
    void albumGotInfo(XmlQuery);
    void artistGotInfo(XmlQuery);
    void artistGotEvents(XmlQuery);
    void trackGotTopFans(XmlQuery);
    void trackGotTags(XmlQuery);
    void finished();

private slots:
    void onTrackStarted(const Track&, const Track&);
    void onStopped();
    void onPaused();
    void onResumed();

    void onItemClicked( class ActivityListItem* clickedItem );
    
private:
    void newTrack( const Track& track );
    void setCurrentWidget( QWidget* );
    void addWinThumbBarButtons( QList<QAction*>& );
    void addNowPlayingToActivityList();

private:
    Track m_currentTrack;
    class ActivityListItem* m_currentActivity;
    class QDockWidget* m_radioSideBar;
    QList<QAction*> m_buttons;
};

#endif //METADATA_WINDOW_H_
