/************* Interface to Qt4 graphics library *************
// Mac Clayton
// mckenzieclayton@gatech.edu
// Spring 2013
// Tested with Qt4.8.4 on OSX 10.8.3
*************************************************************/

#include <QApplication>
#include <QMainWindow>
#include <QVector>

class QTimer;
class QImage;

class QApp : public QApplication 
{
public :
  	QApp(int argc, char** argv);
public:
  	void  Run();                // Process events until all windows closed
};

class QDisplay : public QMainWindow 
{
Q_OBJECT
public:
	QDisplay(QApplication&);    // Requires a QApplication object
	virtual ~QDisplay();        // Destructor
	bool  Load(const char*);    // Load image from a file
	bool  Save(const char*);    // Save image to a file
	void  BlankImage(int w, int h, int d = 8); // Create a blank grayscale image, w by h
	int   Depth();              // Get image depth
	int   Width();              // Get image width
	int   Height();             // Get image height
	unsigned char* ImageData(); // Get image data
	void  Update();             // Update the entire screen image
	void  Update(const QRect&, bool noPaint = false);
	void  Update(int x,int y, int w = 1, int h = 1, bool noPaint = false); // Update a rectangular area
	bool  IsClosed();           // True if main window is closed 
	void  UpdateRate(int);      // Set update rate (frames/sec) 0 = infinite
	void  Run();                // Process events until window closed
	void	Show(bool s = true);
	// Inherited from QMainWindow
	void paintEvent(QPaintEvent*);
	void mousePressEvent(QMouseEvent*);
	// Slots
public slots:
	void timerDone();
	void mainClosed();
private:
	bool           ready;        // If ready to display
	bool           closed;       // If main window closed
	QTimer*        qTimer;       // Ready timer, to enforce 25fps update rate
	QImage*        image;        // Current image
	QApplication&  app;          // Application object
	QPainter*	   dPainter;
	int            updateRate;   // Update rate (frames per sec)
	QVector<QRgb>  colorTable;   // Grayscale color table
	unsigned char* white;        // All white for creating blank images
	int            whitew;       // Width of white buffer
	int            whiteh;       // Height of white buffer
	int 		   whited;			 // Depth of white buffer
	static int     windowCount;  // Number of open windows
};
