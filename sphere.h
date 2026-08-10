/*
Ray-Sphere Intersection 

Equation : if a given point is on the surface of the sphere (centered at the origin), then  x^2 + y^2 + z^2 = r^2
if inside => x^2 + y^2 + z^2 < r^2
if outside => x^2 + y^2 + z^2 > r^2

-> sphere center to be an arbitrary point (Cx, Cy, Cz)
(Cx - x)^2 + (Cy - y)^2 + (Cz - z)^2 = r^2

So, point P = (x,y,z), center C = (Cx, Cy, Cz)
(C-P) . (C-P) = r^2


Want to know if our ray P(t) = Q + td ever hits the sphere anywhere
if it does hit the sphere, there is t for which P(t) satisfies the sphere equation
(C - P(t)) . (C - P(t)) = r^2
(C - (Q+td)) . (C - (Q +td)) = r^2

by solving it we get : 
a = d.d
b = -2d (C-Q)
c = (C-Q).(C-Q) - r^2

t = (-b +- sqrt(b^2 - 4ac) )/ 2a

square root -> positive (2 real solutions), negative (no real solutions), zero (one real solution)

*/