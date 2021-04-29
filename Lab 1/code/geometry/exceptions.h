#ifndef CODE_EXCEPTIONS_H
#define CODE_EXCEPTIONS_H
//Polygon
class polygon_exception: public std::exception{
public:
    polygon_exception() noexcept = default;
    const char * what() const noexcept override{
        return "Incorrect polygon";
    }
};
//Triangle
class triangle_exception: public std::exception{
public:
    triangle_exception() noexcept = default;
    const char * what() const noexcept override{
        return "More/less than 3 points in triangle";
    }
};
//Trapezoid
class trapezoid_points_exception: public std::exception{
public:
    trapezoid_points_exception() noexcept = default;
    const char * what() const noexcept override{
        return "More/less than 4 points in trapezoid";
    }
};
class trapezoid_parallel_exception: public std::exception{
public:
    trapezoid_parallel_exception() noexcept = default;
    const char * what() const noexcept override{
        return "Two parallel lines don't exist";
    }
};
//Regular Polygon
class regular_polygon_exception: public std::exception{
public:
    regular_polygon_exception() noexcept = default;
    const char * what() const noexcept override{
        return "Sides aren't equal";
    }
};
#endif //CODE_EXCEPTIONS_H
