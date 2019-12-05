#ifndef EDGESWAP_TEST_H_
#define EDGESWAP_TEST_H_

#include "SystemStructures.h"

class Edgeswap {
    std::vector<bool> boundary_node;
    std::vector<int> nndata;

    public:
    Edgeswap(CoordInfoVecs& coordInfoVecs, GeneralParams& generalParams);

	std::vector<bool> DomainBd (CoordInfoVecs& coordInfoVecs);
	std::vector<int> Number_of_Neighbor(CoordInfoVecs& coordInfoVecs);

    int growth_host_vecs(int iedge,
    	GeneralParams& generalParams,
	HostSetInfoVecs& hostSetInfoVecs,
	CoordInfoVecs& coordInfoVecs,
	LinearSpringInfoVecs& linearSpringInfoVecs,
	BendingTriangleInfoVecs& bendingTriangleInfoVecs,
	AreaTriangleInfoVecs& areaTriangleInfoVecs);

    int surfaceNormal_device_vecs(int inode,
        CoordInfoVecs& coordInfoVecs,
        GeneralParams& generalParams
    );

    int nodes2Triangles_host_vecs(int inode,
        HostSetInfoVecs& hostSetInfoVecs,
        CoordInfoVecs& coordInfoVecs,
        GeneralParams& generalParams,
        AuxVecs& auxVecs
        );

    int edge_swap_device_vecs (int iedge, 
        GeneralParams& generalParams,
        CoordInfoVecs& coordInfoVecs,
        LinearSpringInfoVecs& linearSpringInfoVecs,
        BendingTriangleInfoVecs& bendingTriangleInfoVecs,
        AreaTriangleInfoVecs& areaTriangleInfoVecs);

    int edge_swap_host_vecs (int SCALE_TYPE, 
        GeneralParams& generalParams,
        HostSetInfoVecs& hostSetInfoVecs,
        LinearSpringInfoVecs& linearSpringInfoVecs,
        BendingTriangleInfoVecs& bendingTriangleInfoVecs,
        AreaTriangleInfoVecs& areaTriangleInfoVecs);
	
    void transferHtoD(GeneralParams& generalParams,
        CoordInfoVecs& coordInfoVecs,
        HostSetInfoVecs& hostSetInfoVecs);
    
    void transferDtoH(GeneralParams& generalParams,
        CoordInfoVecs& coordInfoVecs,
        HostSetInfoVecs& hostSetInfoVecs);
    void gradient_weakening_update_host_vecs(double sigma,
        double max_height_index,
        double distance_to_boundary,
        GeneralParams& generalParams,
        CoordInfoVecs& coordInfoVecs,
        HostSetInfoVecs& hostSetInfoVecs);

};

#endif
