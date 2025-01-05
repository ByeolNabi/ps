// [실5]직사각형
class Rectangle
{
private:
    int width, height;

public:
    Rectangle(int width, int height)
    {
        this->width = width;
        this->height = height;
    }
    int get_width() const { return width; }
    int get_height() const { return height; }
    void set_width(int width)
    {
        if (0 >= width || width > 1000)
            return;
        else
        {
            this->width = width;
        }
    }
    void set_height(int height)
    {
        if (0 >= height || height > 2000)
            return;
        else
        {
            this->height = height;
        }
    };
    int area() const
    {
        int size = get_width() * get_height();
        return size;
    }
    int perimeter() const
    {
        int edge = get_width() * 2 + get_height() * 2;
        return edge;
    }
    bool is_square() const { return (get_width() == get_height() ? true : false); }
};

/*
    void set_width(int width)
    {
        if (0 >= width || width > 1000)
            return;
        else
        {
            this->width = width;
        }
    }
에서 if조건 안에 get을 사용한 width를 사용했다.
입력한 값에 대한 유효성 검사를 해야하는데 이미 할당되어 있는 값에 유효성 검사를 한 것이다...
 */