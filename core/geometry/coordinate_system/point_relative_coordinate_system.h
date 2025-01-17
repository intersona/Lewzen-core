#ifndef __LZ_POINT_RELATIVE_COORDINATE__
#define __LZ_POINT_RELATIVE_COORDINATE__
#include <string>
#include <memory>
#include "../coordinate_system.h"

namespace Lewzen {
    /**
    * Point relative coordinate system information.
    */
    class PointRelativeCoordinateSystem: public CoordinateSystem {
    private:
        // origin
        std::shared_ptr<Point2D> _origin;
        // vertex
        std::shared_ptr<Point2D> _vertex;
    public:
        /**
        * Constructor of PointRelativeCoordinateSystem.
        *
        * @param origin the origin of point relative coordinate system.
        * @param vertex the (1, 1) of point relative coordinate system.
        */
        PointRelativeCoordinateSystem(const std::shared_ptr<Point2D> &origin, const std::shared_ptr<Point2D> &vertex);
        /**
        * Deep copy of this coordinate system.
        */
        PointRelativeCoordinateSystem(const PointRelativeCoordinateSystem &coordinate_system);
        /**
        * Get origin of PointRelativeCoordinateSystem.
        *
        * @return the origin of point relative coordinate system.
        */
        const std::shared_ptr<Point2D> get_origin() const;
        /**
        * Get vertex of PointRelativeCoordinateSystem.
        *
        * @return the vertex of point relative coordinate system.
        */
        const std::shared_ptr<Point2D> get_vertex() const;
        /**
        * Deep copy of this coordinate system.
        *
        * @relatesalso CoordinateSystem
        */
        std::shared_ptr<CoordinateSystem> clone() const;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        bool operator==(const CoordinateSystem &coordinate_system) const override;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        bool operator!=(const CoordinateSystem &coordinate_system) const override;
        /**
        * Get point in corresponding absolute coordinate system.
        *
        * @return point in corresponding absolute coordinate system.
        */
        Point2D to_absolute(const Point2D &p) const;
        /**
        * Convert a point in CanvasCoordinateSystem to this coordinate system.
        *
        * @param p a point in CanvasCoordinateSystem.
        * @return a point in this coordinate system.
        * @throws Lewzen::coordinate_system_mismatch: thrown if point p is not in CanvasCoordinateSystem.
        */
        Point2D from_canvas(const Point2D &p) const override;
        /**
        * Convert a point in this coordinate system to CanvasCoordinateSystem.
        *
        * @param p a point in this coordinate system.
        * @return a point in CanvasCoordinateSystem.
        * @throws Lewzen::coordinate_system_mismatch: thrown if point p is not in this coordinate system.
        */
        Point2D to_canvas(const Point2D &p) const override;
    };
}
#endif