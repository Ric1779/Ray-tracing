#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "rtweekend.h"
#include "aabb.h"

// don't understand this line
class material;

// hit_record is just a way to stuff a bunch of arguments into a class so we can send them as a group.
class hit_record{
    public:
        point3 p;
        vec3 normal;
        shared_ptr<material> mat;
        double t;
        double u;
        double v;
        bool front_face;

        void set_face_normal(const ray& r, const vec3& outward_normal) {
            // Set the hit record normal vector.
            // Note: the parameter 'outward_normal' is assumed to have unit length

            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal; 
        }
};

class hittable{
    public:
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;

        virtual aabb bounding_box() const = 0;
};

#endif