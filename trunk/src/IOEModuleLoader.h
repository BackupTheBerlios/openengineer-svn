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
