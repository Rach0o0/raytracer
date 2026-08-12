#ifndef HITTABLE_H
#define HITTABLE_H

class hit_record {
  public:
    point3 p; 
    vec3 normal;
    double t;
    bool front_face; //true : on touche la face avant

    //on remplit normal et front_face
    void set_face_normal(const ray& r, const vec3& outward_normal){
        //sets the hit record normal vector
        //assumed to have unit length
        front_face = dot(r.direction(),  outward_normal) < 0;
        normal = front_face ? outward_normal : - outward_normal;
    }
};

class hittable {
  public:
    virtual ~hittable() = default;

    //hit function : valid interval tmin, tmax 
    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif