#*************************************************************************#
# NAME OF THE PROJECT:  writeVTK class
# MODULE                writeVTK class.
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
# PURPOSE OF THIS MODULE :  provide a library for the generation of result
#                           files on different vtk formats.
#
# AUTHOR:   Andres Mauricio Aguirre Mesa
#           Universidad EAFIT
# DATE:     June 7, 2015.
# UPDATE:   September 19, 2015
#*************************************************************************#


#*************************************************************************#
class writeVTK:


  #***********************************************************************#
  def __init__(self):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    self.__folder       = ""
    self.__prefix       = ""
    self.__filename     = ""
    self.__maxIt        = 0
    self.__lenMaxIt     = 0
    self.__fid          = ""
    self.__numPoints    = 0;      # Number of points of the vtk file.
    self.__numLines     = 0;      # Number of lines of the vtk file. 
    self.__numTriangs   = 0;      # Number of triangles of the vtk file. 
    self.__numCells     = 0;      # Number of cells of the vtk file. 
    self.__hasPointdata = False;  # Boolean flag for pointdata.
    self.__hasCelldata  = False;  # Boolean flag for celldata.
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def setup(self, folderPath):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    prepare the functions for storing files inside a folder.
    
    Parameters:
                folderPath: the location of a folder to store the vtk files.
                            E.g: "./results/"
    
    Results:    the global variable folder is updated with the provided
                input.
    """
  #***********************************************************************#
    
    # Store the input data into the global variable.
    self.__folder = folderPath

  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def setupForLoops(self, folderPath, name, iterations):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    prepare the vtk functions for generating filenames inside a
                loop and to store them inside a folder.
    
    Parameters:
                folderPath: the location of a folder to store the vtk files.
                            E.g: "./results/"
                name:       a prefix that will be contained in the
                            file names. E.g, if the prefix is "results",
                            the complete path of a results file would
                            look like: "./results/results001.vtk"
                iterations: the maximum number of iterations of the loop.
                            this information is needed to calculate the
                            leading zeros of the filename.
    
    Results:    the global variables folder, prefix and maxIt are updated
                with the provided inputs.
    """
  #***********************************************************************#
  
    # Store the input data into the global variables.

    # The folder's path for storing vtk files.
    self.__folder   = folderPath
    
    # Prefix for filenames.
    self.__prefix   = name

    # Maximum number of iterations.
    self.__maxIt    = iterations   

    # Number of digits of the max number of iterations.
    self.__lenMaxIt = len(str(iterations))

  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def open(self, name):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    open a new vtk file for writing.
    """
  #***********************************************************************#
  
    # Store filename.
    self.__filename = name
  
    # Concatenate full path.
    fullpath = self.__folder + self.__filename
  
    # Open the file for writing.
    self.__fid = open(fullpath, "w")
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def openForLoops(counter):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    open a new vtk file for writing.
    """
  #***********************************************************************#
  
    # Concatenate the filename.
    self.__filename = \
      self.__prefix + str(counter).zfill(self.__lenMaxIt) + ".vtk" 
  
    # Concatenate full path.
    fullpath = self.__folder + self.__filename
    
    # Open the file for writing.
    self.__fid = open(fullpath, "w")
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def close(self):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    close the file to avoid corrupting data.
    """
  #***********************************************************************#
  
    self.__fid.close()
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def newStructuredPoints(self, nx, ny, nz, ox, oy, oz, dx, dy, dz):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:      begin a structured points vtk file.
    
    Description:  structured points is the simplest vtk format. It creates
                  a full regular structured grid, made of rectangles or
                  rectangular boxes as cells, from a few parameters,
                  namely:
                  - The number of divisions along X, Y and Z axes.
                  - The origin of coordinates of the grid.
                  - The spacings along X, Y and Z axes.
    
                  Given the mentioned parameters, the geometry section of
                  the file is fully defined, i.e, Paraview can can create
                  the points and cells based on this information.
    
                  The convention used for indexes growth is: first along X,
                  then along Y, and finally along Z.
    
    Parameters
                  nx, ny, nz: the number of divisions (points) along X, Y
                              and Z.
                  oy. oy, oz: the origin of coordinates of the grid.
                  dx, dy, dz: the spacings of the grid along X, Y and Z.
    
    RESULTS:      the number of points and cells of the grid are stored in
                  their respective global variables. Furthermore, the 
                  headers of the file, including the geometry section, are 
                  written into the previously opened file.
    """
  #***********************************************************************#
  
    # Reset the script variables.
    self.__reset()
  
    # Compute number of cells along each axis
    # The following is the equivalent of the conditional operator ? of C++.
    #    True Value       Condition       False value 
    cx = (nx - 1)     if  (nx > 1)  else  1
    cy = (ny - 1)     if  (ny > 1)  else  1
    cz = (nz - 1)     if  (nz > 1)  else  1
  
    # Remember that cx, cy or cz may not be the real number of cells in X,
    # Y or Z direction when they are approximated to 1. This was done to
    # calculate an appropiate number of cells for either 2D or 3D geometry.
  
    # Store the total number of points and cells of the grid. This
    # information will be required later to verify agreement against the
    # amount of data to be asociated with points and cells.
    self.__numPoints = nx*ny*nz
    self.__numCells  = cx*cy*cz
  
    # Write headers.
    self.__addVtkHeader()
    self.__fid.write("DATASET STRUCTURED_POINTS\n")
    self.__fid.write("DIMENSIONS %d %d %d\n"  %(nx, ny, nz))
    self.__fid.write("ORIGIN %f %f %f\n"      %(ox, oy, oz))
    self.__fid.write("SPACING %f %f %f\n"     %(dx, dy, dz))
  
  #-----------------------------------------------------------------------#

  
  #***********************************************************************#
  def newStructuredGrid(self, points, n1, n2, n3):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    PURPOSE:      begin a structured grid vtk file.
  
    ACCESS:       Public.
  
    DESCRIPTION:  this format automatically provides a full structured grid,
                  made of quadrilaterals or hexahedra as cells (i.e, more
                  general than the structured points format), from the 
                  coordinates of the nodes (points) and the number of 
                  divisions in three directions (not necessarily X, Y and Z).
  
    PARAMETERS
                  points:     the X, Y and Z coordinates of a structured
                              grid made of quadrilaterals or hexahedra.
                  n1, n2, n3: the number of divisions (points) along each
                              direction (not necessarily X, Y and Z).       
  
    RESULTS:      the number of points and cells of the grid are stored in
                  their respective private variables. Furthermore, the 
                  headers of the file, including the geometry section, are 
                  written into the previously opened file.
    """
  #***********************************************************************#
  
    # Reset the script variables.
    self.__reset()
  
    # Compute number of cells along each axis
    # The following is the equivalent of the conditional operator ? of C++.
    #    True Value       Condition       False value 
    c1 = (n1 - 1)     if  (n1 > 1)  else  1
    c2 = (n2 - 1)     if  (n2 > 1)  else  1
    c3 = (n3 - 1)     if  (n3 > 1)  else  1
  
    # Remember that c1, c2 or c3 may not be the real number of cells in the
    # directions defined as 1, 2 or 3 when they are approximated to 1. This
    # was done to calculate an appropiate number of cells for either 2D or
    # 3D geometry.
  
    # Store the total number of points and cells of the grid.
    self.__numPoints = points.shape[0]
    self.__numCells  = c1*c2*c3
    
    # Write headers.
    self.__addVtkHeader()
    self.__fid.write("DATASET STRUCTURED_GRID\n")
    self.__fid.write("DIMENSIONS %d %d %d\n"  %(n1, n2, n3))
  
    # Add points information
    self.__fid.write("POINTS %d DOUBLE\n"  %self.__numPoints)
  
    # Write the content of points into the file
    self.__writeMatrix(points)
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def newPolydata(self, points):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    begin a polygonal data (polydata) vtk file.
    """
  #***********************************************************************#
  
    # Reset the script variables.
    self.__reset()
  
    # Get the number of points
    self.__numPoints = points.shape[0]
  
    # Write headers.
    self.__addVtkHeader()
    self.__fid.write("DATASET POLYDATA\n\n")
  
    # Add points information
    self.__fid.write("POINTS %d DOUBLE\n"  %self.__numPoints)
  
    # Write the content of points into the file
    self.__writeMatrix(points)
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def addLines(self, lines):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    add a group of lines to a polydata vtk file.
    """
  #***********************************************************************#
  
    # Store the total number of lines.
    self.__numLines += lines.shape[0];
    self.__numCells += lines.shape[0];
  
    # Write the lines header.
    self.__fid.write("\nLINES %d %d\n" 
      %(self.__numLines, 3*self.__numLines))
  
    # Write the connectivities.
    self.__writeGeometry(lines)
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def addTriangles(self, triangs):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    add a group of triangles to a polydata vtk file.
    """
  #***********************************************************************#
  
    # Store the total number of triangles.
    self.__numTriangs += triangs.shape[0];
    self.__numCells   += triangs.shape[0];
  
    # Write the triangle strips header.
    self.__fid.write("\nTRIANGLE_STRIPS %d %d\n" 
      %(self.__numCells, 4*self.__numCells))
  
    # Write the connectivities.
    self.__writeGeometry(triangs)
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def addPointdata(self, label, M):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose: add data associated with points.
    """
  #***********************************************************************#
  
    # If the point data header is not present, place it.
    self.__verifyPointdataHeader();
  
    # Convert 1D array to 2D
    if (len(M.shape) == 1):
      M = M.reshape( (M.size, 1) )
    # End if.
    
    # Add scalar or vector header.
    if ( M.shape[1] > 1 ):
      self.__addVectorsHeader(label)
    else:
      self.__addScalarsHeader(label)
    # End if.
  
    # Write matrix to file.
    self.__writeMatrix(M)
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def addCelldata(self, label, M):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose: add data associated with points.
    """
  #***********************************************************************#

    # If the cell data header is not present, place it.
    self.__verifyCelldataHeader();

    # Convert 1D array to 2D
    if (len(M.shape) == 1):
      M = M.reshape( (M.size, 1) )
    # End if.
  
    # Add scalar or vector header.
    if ( M.shape[1] > 1 ):
      self.__addVectorsHeader(label)
    else:
      self.__addScalarsHeader(label)
    # End if.
  
    # Write matrix to file.
    self.__writeMatrix(M)
  
  #-----------------------------------------------------------------------#

  
  #***********************************************************************#
  def __reset(self):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    initialize variables of the script file before the creation
                of a new vtk file.
    """            
  #***********************************************************************#
  
    # Reset the variables.
    self.__numPoints    = 0;      # Number of points of the vtk file.
    self.__numLines     = 0;      # Number of lines of the vtk file. 
    self.__numTriangs   = 0;      # Number of triangles of the vtk file. 
    self.__numCells     = 0;      # Number of cells of the vtk file. 
    self.__hasPointdata = False;  # Boolean flag for pointdata.
    self.__hasCelldata  = False;  # Boolean flag for celldata.
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def __addVtkHeader(self):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    add the default vtk header, common to all formats.
    """
  #***********************************************************************#
  
    self.__fid.write("# vtk DataFile Version 4.2\n\n")
    self.__fid.write("ASCII\n")
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def __writeMatrix(self, M):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    write the contents of a matrix into the file.
    """
  #***********************************************************************#
  
    # Get the number of rows and columns.
    numRows = M.shape[0]
    numCols = M.shape[1]
  
    for i in range(numRows):
  
      for j in range(numCols-1):
  
        self.__fid.write("%f " %M[i,j])
  
      # End for j.

      self.__fid.write("%f\n" %M[i,numCols-1])
  
    # End for i
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def __writeGeometry(self, M):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:    write connectivities into the file
    """
  #***********************************************************************#
  
    # Get the number of cells and vertex from the connectivities array.
    numCells = M.shape[0]
    vertices = M.shape[1]
  
    for i in range(numCells):
    
      # Write the number of vertices at the beginning of the line.
      self.__fid.write("%d " %vertices)
  
      for j in range (vertices-1):
  
        self.__fid.write("%d " %M[i,j])
  
      # End for j.
  
      self.__fid.write("%d\n" %M[i, vertices-1])
  
    # End for i.
  
  #-----------------------------------------------------------------------#

  #***********************************************************************#
  def __verifyPointdataHeader(self):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:  write the point data header if it's not done.
    """ 
  #***********************************************************************#
  
    if ( not self.__hasPointdata ):
  
      # Write the header.
      self.__fid.write("\nPOINT_DATA %d" %self.__numPoints)
  
      # Change flag value.
      self.__hasPointdata = True
  
    # End if.
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def __verifyCelldataHeader(self):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:  write the cell data header if it's not done.
    """ 
  #***********************************************************************#
  
    if ( not self.__hasCelldata ):
  
      # Write the header.
      self.__fid.write("\nCELL_DATA %d"  %self.__numCells)
  
      # Change flag value.
      self.__hasCelldata = True
  
    # End if.

  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def __addScalarsHeader(self, label):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:  add the scalars header for pointData and cellData.
    """
  #***********************************************************************#
  
    self.__fid.write("\nSCALARS %s double\n" %label)
    self.__fid.write("LOOKUP_TABLE default\n")
  
  #-----------------------------------------------------------------------#


  #***********************************************************************#
  def __addVectorsHeader(self, label):
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
    """
    Purpose:  add the vectors header for pointData and cellData.
    """
  #***********************************************************************#
  
    self.__fid.write("\nVECTORS %s double\n" %label)
  
  #-----------------------------------------------------------------------#


#----------------------- End of the WriteVTK class -----------------------#
