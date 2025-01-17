#ifndef __LZ_POINT__
#define __LZ_POINT__
#include <string>
#include <memory>
#include "coordinate_system.h"

namespace Lewzen {
    class CoordinateSystem;
    /**
    * A 2D point.
    */
    class Point2D {
    private:
        // position (x, y)
        double _x, _y;
        // corrdiante information
        std::shared_ptr<CoordinateSystem> _coordinate_system;
    public:
        /**
        * Constructor of SVG Element. The coordinate system is 'NULL'.
        *
        * @param x x position.
        * @param y y position.
        */
        Point2D(const double &x, const double &y);
        /**
        * Constructor of SVG Element.
        *
        * @param x x position.
        * @param y y position.
        * @param coordinate system coordinate system information.
        */
        Point2D(const double &x, const double &y, const CoordinateSystem &coordinate_system);
        /**
        * Deep copy of point.
        */
        Point2D(const Point2D &point);

        /// Property
        /**
        * Get coordinate system information.
        *
        * @return coordinate system information.
        */
        const CoordinateSystem &get_coordinate_system() const;
        /**
        * Get x position.
        *
        * @return x position.
        */
        double get_x() const;
        /**
        * Set x position.
        *
        * @param x x position.
        */
        void set_x(const double &x);
        /**
        * Get y position.
        *
        * @return y position.
        */
        double get_y() const;
        /**
        * Set y position.
        *
        * @param x y position.
        */
        void set_y(const double &y);
        /**
        * Move (x, y) to (x + dx, y + dy).
        *
        * @param dx delta x.
        * @param dy delta y.
        */
        void move(const double &dx, const double &dy);

        /**
        * Deep copy of point.
        *
        * @relatesalso Point2D
        */
        virtual std::shared_ptr<Point2D> clone() const;
        /**
        * Compare two points. Compare x, y and coordinate system.
        *
        * @relatesalso Point
        */
        bool operator==(const Point2D &point) const;
        /**
        * Let this point equals to another point. Two points should be in the same coordinate system.
        *
        * @relatesalso Point
        */
        Point2D &operator=(const Point2D &point);
        /**
        * Add another point to this point. Two points should be in the same coordinate system.
        *
        * @relatesalso Point
        */
        Point2D &operator+=(const Point2D &point);
        /**
        * Substract another point from this point. Two points should be in the same coordinate system.
        *
        * @relatesalso Point
        */
        Point2D &operator-=(const Point2D &point);
        /**
        * Point addition. Two points should be in the same coordinate system.
        *
        * @relatesalso Point
        */
        Point2D operator+(const Point2D &point) const;
        /**
        * Point substraction. Two points should be in the same coordinate system.
        *
        * @relatesalso Point
        */
        Point2D operator-(const Point2D &point) const;
        /**
        * Convert this point to another coordinate.
        *
        * @relatesalso CoordinateSystem
        */
        Point2D operator() (const CoordinateSystem &coordinate_system) const;
    };
}
#endif