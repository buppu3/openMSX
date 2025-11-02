#ifndef VDPCMDCACHE_HH
#define VDPCMDCACHE_HH

namespace openmsx::VDPCmdCache {
enum class CachePenalty : int {
	CACHE_NONE          = 0,
	CACHE_READ_HIT 		= 1,
	CACHE_READ_MISS 	= 2,
	CACHE_READ_FLUSH	= 3,
	CACHE_WRITE_HIT 	= 4,
	CACHE_WRITE_MISS 	= 5,
	CACHE_WRITE_FLUSH 	= 6,
	CACHE_FLUSH_0		= 7,
	CACHE_FLUSH_1		= 8,
	CACHE_FLUSH_2		= 9,
	CACHE_FLUSH_3		= 10,
	CACHE_FLUSH_4		= 11
};

// ToDo: Move the cache processing from VDPCmdEngine.hh
}

#endif
