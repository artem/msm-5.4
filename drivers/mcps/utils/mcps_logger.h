#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <linux/printk.h>

#define mcps_err(fmt, ...) pr_err("MCPSE[%d] %s : "fmt"\n", raw_smp_processor_id(), __func__, ##__VA_ARGS__)
#define mcps_dbg(fmt, ...) pr_debug("MCPSD[%d] %s : "fmt"\n", raw_smp_processor_id(), __func__, ##__VA_ARGS__)

#if defined(CONFIG_KUNIT)

#ifndef __visible_for_testing
#define __visible_for_testing
#endif //#ifndef __visible_for_testing

#define mcps_warn_on(cond)

#else // #if defined(CONFIG_KUNIT)

#ifndef __visible_for_testing
#define __visible_for_testing static
#endif //#ifndef __visible_for_testing

#define mcps_warn_on(cond) WARN_ON((cond))

#endif // #if defined(CONFIG_KUNIT)

#endif
