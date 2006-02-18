/*
 * Name		:	IOEModuleLoader.h
 * Comment	:	Declares an interface IOEModuleLoader, that every 
 * 			module loader should implement
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
 
#ifndef __OE_IMODULELOADER_HEADER__
#define __OE_IMODULELOADER_HEADER__

abstract class IOEModuleLoader
{
public:
	virtual IOEModule* LoadModule (
					const char* modName,
					OEBasicFrame* frame,
					const char* filename,
					int moduleFlags) = 0;
	virtual bool UnLoadModule (IOEModule* mod) = 0;
};

#endif /* __OE_IMODULELOADER_HEADER__ */
