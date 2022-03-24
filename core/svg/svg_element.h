#include <string>
#ifndef __LZ_SVG_ELEMENT__
#define __LZ_SVG_ELEMENT__

namespace Lewzen {
    /**
    * The SVG element.
    */
    class SVGElement {
    private:
        std::map<double, WayPoint *> _way_points;
        SVGFillStyle *_fill_style;
        SVGStrokeStyle *_stroke_style;
    public:
         /**
        * Constructor of SVG Element.
        */
        SVGElement();
        /**
        * Destructor of SVG Element.
        */
        ~SVG();

        /// Way Points
        /**
        * Get all way points in way point list.
        *
        * @return the pointer list of the way points.
        */
        const std::vector<WayPoint *> get_way_points() const;
        /**
        * Convert the rank in way point list to way point's number.
        *
        * @param rank the rank in way point list.
        * @return way point's number.
        */
        double rank_to_num(const int &rank) const;
        /**
        * Convert way point's number to the rank in way point list.
        *
        * @param num way point's number.
        * @return the rank in way point list.
        */
        double num_to_rank(const double &num) const;
        /**
        * Get a way point in way point list.
        *
        * @param rank the rank in way point list.
        * @return the pointer of the way point; NULL for non-exist.
        */
        WayPoint *get_way_point(const int &rank) const;
        /**
        * Get a way point in way point list.
        *
        * @param num way point's number.
        * @return the pointer of the way point; NULL for non-exist.
        */
        WayPoint *get_way_point(const double &num) const;
        /**
        * Add a new way point to way point list.
        *
        * @param way_point the pointer of way point to be added.
        */
        void add_way_point(WayPoint *way_point);
        /**
        * Remove a SVG element from SVG.
        *
        * @param num way point's number.
        * @return true for successful removal.
        */
        bool remove_way_point(const double &num);

        /// Styles
        /**
        * Get the fill style of the SVG element.
        *
        * @return the pointer of the SVG element.
        */
        SVGFillStyle *get_fill_style() const;
        /**
        * Copy and set the fill style of the SVG element.
        *
        * @param fill_style_to_copy the fill style to copy.
        */
        SVGFillStyle *set_fill_style(SVGFillStyle &fill_style_to_copy);
        /**
        * Get the stroke style of the SVG element.
        *
        * @return the pointer of the SVG element.
        */
        SVGStrokeStyle *get_stroke_style() const;
        /**
        * Copy and set the stroke style of the SVG element.
        *
        * @param stroke_style_to_copy the stroke style to copy.
        */
        SVGStrokeStyle *set_stroke_style(SVGStrokeStyle &stroke_style_to_copy);

        /// Functional
        /**
        * Parse this SVG element object to XML.
        */
        virtual std::string to_XML() const;
        /**
        * Determine if a point is inside this SVG element.
        *
        * @param point the point, must in Component Coordinate System or Component Relative Coordinate System.
        * @return true for the point being in this SVG element.
        */
        virtual bool is_in(const Point2D &point) const;
    }
}
#endif