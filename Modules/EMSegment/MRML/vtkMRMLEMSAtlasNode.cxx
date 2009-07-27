/*=auto=======================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights
  Reserved.

  See Doc/copyright/copyright.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkMRMLEMSAtlasNode.cxx,v$
  Date:      $Date: 2006/01/06 17:56:51 $
  Version:   $Revision: 1.6 $
  Author:    $Nicolas Rannou (BWH), Sylvain Jaume (MIT)$

=======================================================================auto=*/

#include "vtkMRMLEMSAtlasNode.h"
#include <sstream>
#include "vtkMRMLScene.h"
#include <algorithm>

#include <vtksys/ios/sstream>

//----------------------------------------------------------------------------
vtkMRMLEMSAtlasNode* vtkMRMLEMSAtlasNode::New()
{
  // First try to create the object from the vtkObjectFactory
  vtkObject* ret = vtkObjectFactory::CreateInstance("vtkMRMLEMSAtlasNode");

  if (ret)
  {
    return (vtkMRMLEMSAtlasNode*)ret;
  }

  // If the factory was unable to create the object, then create it here.
  return new vtkMRMLEMSAtlasNode;
}

//----------------------------------------------------------------------------
vtkMRMLNode* vtkMRMLEMSAtlasNode::CreateNodeInstance()
{
  // First try to create the object from the vtkObjectFactory
  vtkObject* ret = vtkObjectFactory::CreateInstance("vtkMRMLEMSAtlasNode");

  if(ret)
    {
    return (vtkMRMLEMSAtlasNode*)ret;
    }

  // If the factory was unable to create the object, then create it here.
  return new vtkMRMLEMSAtlasNode;
}

//----------------------------------------------------------------------------
vtkMRMLEMSAtlasNode::vtkMRMLEMSAtlasNode()
{
  NumberOfTrainingSamples = 82;
}

//----------------------------------------------------------------------------
vtkMRMLEMSAtlasNode::~vtkMRMLEMSAtlasNode()
{
  // nothing to do here
}

//----------------------------------------------------------------------------
void vtkMRMLEMSAtlasNode::WriteXML(ostream& of, int nIndent)
{
  Superclass::WriteXML(of, nIndent);
  vtkIndent indent(nIndent);

  of << indent << "NumberOfTrainingSamples=\""
    << this->NumberOfTrainingSamples << "\"";
}

//----------------------------------------------------------------------------
void vtkMRMLEMSAtlasNode::ReadXMLAttributes(const char** attrs)
{
  Superclass::ReadXMLAttributes(attrs);

  const char* key;
  const char* val;

  while (*attrs != NULL)
    {
    key = *attrs++;
    val = *attrs++;

    if (!strcmp(key, "NumberOfTrainingSamples"))
      {
      vtksys_stl::stringstream ss;
      ss << val;
      ss >> this->NumberOfTrainingSamples;
      }
    }
}

//----------------------------------------------------------------------------
void vtkMRMLEMSAtlasNode::Copy(vtkMRMLNode *rhs)
{
  Superclass::Copy(rhs);

  vtkMRMLEMSAtlasNode* node = (vtkMRMLEMSAtlasNode*) rhs;

  this->SetNumberOfTrainingSamples(node->NumberOfTrainingSamples);
}

//----------------------------------------------------------------------------
void vtkMRMLEMSAtlasNode::PrintSelf(ostream& os, vtkIndent indent)
{
  Superclass::PrintSelf(os, indent);

  os << indent << "NumberOfTrainingSamples: "
     << this->NumberOfTrainingSamples << "\n";
}

