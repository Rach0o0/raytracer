COMPILATION : 
./run.sh
eog images/output.ppm


SENDING RAYS INTO THE SCENE : 

Setps are : 
- Calculate the ray from the "eye" through the pixel
- Determine which objects the ray intersects
- Compute a color for the closest interection point


DEFINITIONS : 

- aspect ratio : width:length
- viewport : rectangle virtuel placé devant la caméra dans l'espace 3D qui représente ce que "voit" l'image finale (window)
- pixel spacing : distance btwn two adjacent pixels
- camera center / eye point : point in 3D space from which all scene rays will originate 
- focal length : distance btwn viewport and eye point (often one unit)


CAMERA & COORDINATES : 
- centre de la caméra est en (0,0,0), tous les rayons partent de ce point 
- viewport est un rectangle placé devant, perpendiculaire à la direction du regard, à une distance de 1 unité (centre du viewport en (0,0,-1))
- Axe Y : dans le monde 3D, pixel (0,0) en haut à gauche 
- pixel décalé d'un demi pas dans chaque direction (pixel est une petite case )

Ray-Sphere Intersection 
- Equation : if a given point is on the surface of the sphere (centered at the origin), then  x^2 + y^2 + z^2 = r^2, if inside => x^2 + y^2 + z^2 < r^2, if outside => x^2 + y^2 + z^2 > r^2
- sphere center to be an arbitrary point (Cx, Cy, Cz), (Cx - x)^2 + (Cy - y)^2 + (Cz - z)^2 = r^2
- So, point P = (x,y,z), center C = (Cx, Cy, Cz), (C-P) . (C-P) = r^2
- Want to know if our ray P(t) = Q + td ever hits the sphere anywhere
- if it does hit the sphere, there is t for which P(t) satisfies the sphere equation
(C - P(t)) . (C - P(t)) = r^2
(C - (Q+td)) . (C - (Q +td)) = r^2
- by solving it we get : 
a = d.d
b = -2d (C-Q)
c = (C-Q).(C-Q) - r^2
t = (-b +- sqrt(b^2 - 4ac) )/ 2a
- square root -> positive (2 real solutions), negative (no real solutions), zero (one real solution)

SHADING 
- we need normal to shade : vector that is perpendicular to the surface at the point of intersection (normal vectors will be of unit length)
- la normale on peut la faire pointer fans deux directions opposées : toujours vers l'exterieur de l'objet, toujours contre le rayon 
--> pointera toujours contre le rayon 

ANTIALIASING : 
- if we zoon into the rendered images, notice harsh "stair step" nature of edges --> aliasing
- true image is continuous (infinite resolution)
- get the same effect by averaging a bunch of samples for each pixel
- point sampling : single ray through the center of each pixel 
- we want to integrate the light falling on a particular region of our rendered image
- sampling the square region centered at the pixel that extends halfway to each of the four neighboring pixels (simplest model)

DIFFUSE MATERIALS : 
- realistic looking materials 
- diffuse materials (matte)
- diffuse objects take on the color of their surroundings, but they modulate that with their own intrinsic color
- light that reflects off a diffuse surface has its direction randomized
- might be absorbed (darker surface)