# include <queue>
# include <uC++.h>
using namespace std;

_Monitor Buffer
{
	private:
		queue<Image> images;
	public:
		Buffer(){};
		Image b_pop() {Image img = images.front(); images.pop(); return img;}
		void b_push(Image image) {images.push(image);}
};