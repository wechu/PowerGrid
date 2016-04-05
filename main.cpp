#include <qfile.h>
#include <qstring.h>

#include "mainframe.h"
#include "application.h"

#include "Game.h"

int main(int argc, char *argv[]) {

	// Create game
	Game game;

	// Play
	// game.PlayGame();

	// Application
	Application application(argc, argv);

	// Load css
	QFile File(":/PowerGrid/Resources/stylesheet.qss");
	File.open(QFile::ReadOnly);
	QString StyleSheet = QLatin1String(File.readAll());

	// Main frame
	// Should this be a pointer or passing the address works ?
	MainFrame mainframe("Power Grid", &application);

	// Apply css
	application.setStyleSheet(StyleSheet);

	// Return
	return application.exec();
}