
#include "adm.h"

// ADM Header files.  This listing may be auto-generated in the future
#include "adm_amp_agent.h"
#include "adm_bp_agent.h"
#include "adm_ion_admin.h"
#include "adm_ion_ipn_admin.h"
#include "adm_ionsec_admin.h"
#include "adm_ion_ltp_admin.h"
#include "adm_ltp_agent.h"
#include "adm_ion_bp_admin.h"

#ifdef BUILD_BPv6
#include "adm_sbsp.h"
#else
#include "adm_bpsec.h"
#endif

/******************************************************************************
 *
 * \par Function Name: adm_init
 *
 * \par Initialize pre-configured ADMs.
 *
 * \par Notes:
 *
 * Modification History:
 *  MM/DD/YY  AUTHOR         DESCRIPTION
 *  --------  ------------   ---------------------------------------------
 *  11/25/12  E. Birrane     Initial implementation.
 *  12/01/19  D. Edell       Split into adm_common() and adm_common_init() to
 *                             break potential circular dependencies.
 *****************************************************************************/

void adm_init()
{
   adm_common_init();

#ifdef ADM_DYNAMIC_LOADER
	/*
	  PLACEHOLDER for future dynamic loader concept for target systems supporting dlopen
	  - List files in configured plugins directory (*.so - extension may vary by OS)
	  - Filenames shall be of the standard form libAdm$NAME.so
	  - After loading (dlopen), the function $NAME_init() will be called for each file (dlsym() to lookup).
	 */
#else // Default statically defined set
   // NOTE: The following section may be modified to be auto-generated by Makefile in future.
	amp_agent_init();
	dtn_bp_agent_init();
	dtn_ion_ionadmin_init();
	dtn_ion_ipnadmin_init();
	dtn_ion_ionsecadmin_init();
	dtn_ion_ltpadmin_init();
	dtn_ltp_agent_init();
	dtn_ion_bpadmin_init();
	
#ifdef BUILD_BPv6
	dtn_sbsp_init();
#else
	dtn_bpsec_init();
#endif

#endif
	AMP_DEBUG_EXIT("adm_init","->.", NULL);
}
