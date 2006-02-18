/*
 * Name		:	OEDebug.h
 * Comment	:	Declares function prototypes of all debug
 * 			related features of the software
 * License	:	(c)2006 Hariprasad Govardhanam
 * 			Released under BSD-Style License
 * 			Please LICENSE file accompanying this source
 * Changes	:	
 */
 
#ifndef __OE_DEBUG_HEADER__
#define __OE_DEBUG_HEADER__

/////////////////////////////////////////////////////////////////////
// Standard include files


/////////////////////////////////////////////////////////////////////
// User-Defined include files


/* Debugging Levels 
 * DL_ALL - Every message including entering and exiting a function
 * DL_SEL - Only selected messages
 * DL_WARN - Warning messages 
 * DL_ERR - Error messages will be in this level
 *
 * These are levels, depending on the minimum level selected
 * messages of the same or above level are printed and other's
 * are ignored
 */
enum OE_DLEVEL { DL_ALL, DL_SEL, DL_WARN, DL_ERR };

void oe_dbg_msg_handler (const wxString& msg, OE_DLEVEL level);


/* Macros are choosen for each of the level because
 * we can let remove some kind of messages when NDEBUG
 * is defined
 */
#ifdef NDEBUG
#	define DBG_MSG(msg)
#else
#	define DBG_MSG(msg) oe_dbg_msg_handler (msg, DL_ALL)
#endif

#ifdef NDEBUG
#	define SEL_MSG(msg)
#else
#	define SEL_MSG(msg) oe_dbg_msg_handler (msg, DL_SEL)
#endif

#define WARN_MSG(msg)	oe_dbg_msg_handler (msg, DL_WARN)

#define ERR_MSG(msg)	oe_dbg_msg_handler (msg, DL_ERR)

#endif /* __OE_DEBUG_HEADER__ */
