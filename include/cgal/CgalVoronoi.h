#ifndef _CGAL_VORONOI_H
#define _CGAL_VORONOI_H



#include <QImage>



#include <CGAL/Polygon_2.h>

// includes for defining the Voronoi diagram adaptor
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Voronoi_diagram_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_traits_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_policies_2.h>

namespace CgalVoronoi{

// typedefs for defining the adaptor
typedef CGAL::Exact_predicates_inexact_constructions_kernel                  K;
typedef CGAL::Delaunay_triangulation_2<K>                                    DT;
typedef CGAL::Delaunay_triangulation_adaptation_traits_2<DT>                 AT;
typedef CGAL::Delaunay_triangulation_caching_degeneracy_removal_policy_2<DT> AP;
typedef CGAL::Voronoi_diagram_2<DT,AT,AP>                                    VD;

// typedef for the result type of the point location
typedef AT::Site_2                    Site_2;
typedef AT::Point_2                   Point_2;

typedef VD::Locate_result             Locate_result;
typedef VD::Vertex_handle             Vertex_handle;
typedef VD::Face_handle               Face_handle;
typedef VD::Halfedge_handle           Halfedge_handle;
typedef VD::Ccb_halfedge_circulator   Ccb_halfedge_circulator;

}

#include "VoriGraph.h"

/// create a vori graph using a number of occupied points 
bool createVoriGraph(const std::vector<topo_geometry::point> &sites, VoriGraph &voriGraph, VoriConfig *sConfig);


/// remove all vertices and edges outsite a given polygon. Edges cut by the polygon are turned into rays. Typically used with a polygon generated by an alpha shape algorithm.
void removeOutsidePolygon(VoriGraph &voriGraph, CGAL::Polygon_2<CgalVoronoi::K> &polygon);

void paintVoronoi(QImage &image, CgalVoronoi::VD & vd);


#endif
