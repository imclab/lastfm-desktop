/*
   Copyright 2005-2009 Last.fm Ltd.
      - Primarily authored by Max Howell, Jono Cole and Doug Mansell

   This file is part of the Last.fm Desktop Application Suite.

   lastfm-desktop is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   lastfm-desktop is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with lastfm-desktop.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "lib/unicorn/StylableWidget.h"
#include "lib/DllExportMacro.h"

class UNICORN_DLLEXPORT ItemSelectorWidget : public StylableWidget
{
    Q_OBJECT
private:
    struct
    {
        class SearchBox* searchBox;
    } ui;

public:
    enum Type
    {
        Tag,
        User
    };

    explicit ItemSelectorWidget(Type type, QWidget* parent = 0);

    QStringList items() const;

signals:
    void changed();

private slots:
    void onItemSelected();
    void onDeletePressed();
    void onItemDeleted( class SelectedItemWidget* recipient );

    void onCompleterActivated( const QString& text );
    void onTextChanged( const QString& text );

private:
    void addItem( const QString& text );
    bool itemsContain( const QString& text );

private:
    QList<class SelectedItemWidget*> m_items;
    bool m_clearText;
};
