1. Sending rays into the scene

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