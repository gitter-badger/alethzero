/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file SendDialog.cpp
 * @author Gav Wood <i@gavwood.com>
 * @date 2014
 */

#pragma once

#include <QDialog>
#include <libethcore/Common.h>

namespace Ui {
class SendDialog;
}

namespace dev
{
namespace aleth
{

class AlethFace;

class SendDialog: public QDialog
{
	Q_OBJECT

public:
	SendDialog(QWidget* _parent, AlethFace* _aleth);
	~SendDialog();

private slots:
	void on_send_clicked();
	void on_cancel_clicked();
	void on_value_textChanged(QString _s);
	void on_to_textChanged(QString _s);

private:
	void updateProblem();

	Ui::SendDialog* m_ui;
	AlethFace* m_aleth;

	u256 m_value = UndefinedU256;
	Address m_to;
	bytes m_data;
};

}
}
