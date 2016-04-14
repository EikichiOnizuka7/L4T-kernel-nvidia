#ifndef MTS_MCE_ARI_H
#define MTS_MCE_ARI_H

/*
 * Copyright (c) 2015-2016, NVIDIA CORPORATION. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * ----------------------------------------------------------------------------
 * mce_ari.h
 *
 * global ARI definitions. This file can be included from DNI and Tegra SW
 * ----------------------------------------------------------------------------
 */

/*
 * WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
 * Be careful changing/adding the indexes below.
 * Some changes may require updates in DMCE sequences!
 * All changes require increasing ARI version numbers
 * Changing/removing indexes requires increasing the major version number
 * WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
 */

typedef enum {
	/* indexes below get the core lock */
	MCE_ARI_MISC = 0,
	MCE_ARI_UPDATE_CROSSOVER_OLD_OBSOLETE,
	MCE_ARI_READ_CSTATE_STATS,
	MCE_ARI_WRITE_CSTATE_STATS,

	/* indexes below need cluster lock */
	MCE_ARI_COPY_MISCREG_AA64_RST = 40,
	MCE_ARI_MISC_CLUSTER,

	/* indexes below need ccplex lock */
	MCE_ARI_ENTER_CSTATE = 80,
	MCE_ARI_UPDATE_CSTATE_INFO,
	MCE_ARI_IS_SC7_ALLOWED,
	MCE_ARI_ONLINE_CORE,
	MCE_ARI_PERFMON,
	MCE_ARI_UPDATE_CCPLEX_GSC,
	MCE_ARI_VGIC_REMAP,
	MCE_ARI_CC3_CTRL,
	MCE_ARI_ROC_FLUSH_CACHE_ONLY,
	MCE_ARI_ROC_FLUSH_CACHE_TRBITS,
	MCE_ARI_MISC_CCPLEX,
	MCE_ARI_MCA,
	MCE_ARI_UPDATE_CROSSOVER,
} dmce_ari_req_id_t;

enum {
	MCE_ARI_VERSION_MAJOR = 2,
	MCE_ARI_VERSION_MINOR = 5,
};

typedef enum {
	MCE_ARI_MISC_ECHO = 0,
	MCE_ARI_MISC_VERSION = 1,
	MCE_ARI_MISC_FEATURE_LEAF_0 = 2,
	MCE_ARI_MISC_CONTROL = 8,
} dmce_ari_misc_index_t;

typedef enum {
	MCE_ARI_MISC_CCPLEX_SHUTDOWN_POWER_OFF = 0,
	MCE_ARI_MISC_CCPLEX_SHUTDOWN_REBOOT = 1,
} dmce_ari_misc_ccplex_index_t;

typedef enum {
	MCE_ARI_CORE_C0 = 0,
	MCE_ARI_CORE_C1 = 1,
	MCE_ARI_CORE_C3 = 3,
	MCE_ARI_CORE_C6 = 6,
	MCE_ARI_CORE_C7 = 7,
	MCE_ARI_CORE_WARMRSTREQ = 8,
} dmce_ari_core_sleep_state_t;

typedef enum {
	MCE_ARI_CLUSTER_CC0 = 0,
	MCE_ARI_CLUSTER_CC1 = 1,
	MCE_ARI_CLUSTER_CC3 = 3,
	MCE_ARI_CLUSTER_CC6 = 6,
	MCE_ARI_CLUSTER_CC7 = 7,
} dmce_ari_cluster_sleep_state_t;

typedef enum {
	MCE_ARI_CCPLEX_CCP0 = 0,
	MCE_ARI_CCPLEX_CCP1 = 1,
	MCE_ARI_CCPLEX_CCP3 = 3,
} dmce_ari_ccplex_sleep_state_t;

typedef enum {
	MCE_ARI_SYSTEM_SC0 = 0,
	MCE_ARI_SYSTEM_SC1 = 1,
	MCE_ARI_SYSTEM_SC2 = 2,
	MCE_ARI_SYSTEM_SC3 = 3,
	MCE_ARI_SYSTEM_SC4 = 4,
	MCE_ARI_SYSTEM_SC7 = 7,
	MCE_ARI_SYSTEM_SC8 = 8,
} dmce_ari_system_sleep_state_t;

typedef enum {
	MCE_ARI_CROSSOVER_C1_C6 = 0,
	MCE_ARI_CROSSOVER_CC1_CC6 = 1,
	MCE_ARI_CROSSOVER_CC1_CC7 = 2,
	MCE_ARI_CROSSOVER_CCP1_CCP3 = 3,
	MCE_ARI_CROSSOVER_CCP3_SC2 = 4,
	MCE_ARI_CROSSOVER_CCP3_SC3 = 5,
	MCE_ARI_CROSSOVER_CCP3_SC4 = 6,
	MCE_ARI_CROSSOVER_CCP3_SC7 = 7,
	MCE_ARI_CROSSOVER_CCP3_SC1 = 8,
} dmce_ari_crossover_index_t;

typedef enum {
	MCE_ARI_READ_CSTATE_STATS_CLEAR,
	MCE_ARI_READ_CSTATE_STATS_SC7_ENTRIES = 1,
	MCE_ARI_READ_CSTATE_STATS_SC4_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_SC3_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_SC2_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_CCP3_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_A57_CC6_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_A57_CC7_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_D15_CC6_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_D15_CC7_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_D15_0_C6_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_D15_1_C6_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_D15_0_C7_ENTRIES = 14,
	MCE_ARI_READ_CSTATE_STATS_D15_1_C7_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_A57_0_C7_ENTRIES = 18,
	MCE_ARI_READ_CSTATE_STATS_A57_1_C7_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_A57_2_C7_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_A57_3_C7_ENTRIES,
	MCE_ARI_READ_CSTATE_STATS_LAST_CSTATE_ENTRY_D15_0,
	MCE_ARI_READ_CSTATE_STATS_LAST_CSTATE_ENTRY_D15_1,
	MCE_ARI_READ_CSTATE_STATS_LAST_CSTATE_ENTRY_A57_0 = 26,
	MCE_ARI_READ_CSTATE_STATS_LAST_CSTATE_ENTRY_A57_1,
	MCE_ARI_READ_CSTATE_STATS_LAST_CSTATE_ENTRY_A57_2,
	MCE_ARI_READ_CSTATE_STATS_LAST_CSTATE_ENTRY_A57_3,
	MCE_ARI_READ_CSTATE_STATS_MAX = MCE_ARI_READ_CSTATE_STATS_LAST_CSTATE_ENTRY_A57_3,
} dmce_ari_read_cstate_stats_index_t;

typedef enum {
	MCE_ARI_GSC_ALL  =  0,
	MCE_ARI_GSC_FIRST_IDX = 1,
	MCE_ARI_GSC_LAST_IDX = 35,
	MCE_ARI_GSC_NUM_MC_GSC = 29,

	MCE_ARI_GSC_NVDEC = 1,
	MCE_ARI_GSC_WPR1 = 2,
	MCE_ARI_GSC_WPR2 = 3,
	MCE_ARI_GSC_TSECA = 4,
	MCE_ARI_GSC_TSECB = 5,
	MCE_ARI_GSC_BPMP = 6,
	MCE_ARI_GSC_APE = 7,
	MCE_ARI_GSC_SPE = 8,
	MCE_ARI_GSC_SCE = 9,
	MCE_ARI_GSC_APR = 10,
	MCE_ARI_GSC_TZRAM = 11,
	MCE_ARI_GSC_SE = 12,
	MCE_ARI_GSC_DMCE = 13,
	MCE_ARI_GSC_BPMP_TO_DMCE = 14,
	MCE_ARI_GSC_DMCE_TO_BPMP = 15,
	MCE_ARI_GSC_BPMP_TO_SPE = 16,
	MCE_ARI_GSC_SPE_TO_BPMP = 17,
	MCE_ARI_GSC_CPU_TZ_TO_BPMP = 18,
	MCE_ARI_GSC_BPMP_TO_CPU_TZ = 19,
	MCE_ARI_GSC_CPU_NS_TO_BPMP = 20,
	MCE_ARI_GSC_BPMP_TO_CPU_NS = 21,
	MCE_ARI_GSC_IPC_SE_SPE_SCE_BPMP = 22,
	MCE_ARI_GSC_SC7_RESUME_FW = 23,
	MCE_ARI_GSC_TEMP_BO_MTS_PACKAGE = 28,
	MCE_ARI_GSC_TEMP_BO_MCE_PREBOOT = 29,

	MCE_ARI_GSC_TZ_DRAM_IDX = 34,
	MCE_ARI_GSC_VPR_IDX = 35,
} dmce_ari_gsc_index_t;

/* This macro will produce enums for __name##_LSB, __name##_MSB and __name##_MSK */
#define MCE_ARI_ENUM_MASK_LSB_MSB(__name,__lsb,__msb) __name##_LSB = __lsb, __name##_MSB = __msb, __name##_MSK = ((1ull << __msb) | (((1ull << __msb) - 1) ^ ((1ull << __lsb) - 1)))

typedef enum {
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MISC_CTRL__CORESIGHT_CLOCKGATE, 0, 0),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MISC_CTRL__CONTROL_CORESIGHT_CLOCKGATE, 1, 1),

	MCE_ARI_MISC_CTRL__DEFINED_FIELDS = MCE_ARI_MISC_CTRL__CORESIGHT_CLOCKGATE_MSK |
				MCE_ARI_MISC_CTRL__CONTROL_CORESIGHT_CLOCKGATE_MSK,
} dmce_ari_misc_ctrl_bitmasks_t;

typedef enum {
	MCE_ARI_MCA_NOP = 0,
	MCE_ARI_MCA_READ_SERR = 1,
	MCE_ARI_MCA_WRITE_SERR = 2,
	MCE_ARI_MCA_CLEAR_SERR = 4,
	MCE_ARI_MCA_REPORT_SERR = 5,
	MCE_ARI_MCA_READ_INTSTS = 6,
	MCE_ARI_MCA_WRITE_INTSTS = 7,
} dmce_ari_mca_commands_t;

typedef enum {
	MCE_ARI_MCA_RD_WR_DPMU = 0,
	MCE_ARI_MCA_RD_WR_IOB = 1,
	MCE_ARI_MCA_RD_WR_MCB = 2,
	MCE_ARI_MCA_RD_WR_CCE = 3,
	MCE_ARI_MCA_RD_WR_CQX = 4,
	MCE_ARI_MCA_RD_WR_CTU = 5,
	MCE_ARI_MCA_RD_BANK_INFO = 0x0f,
	MCE_ARI_MCA_RD_BANK_TEMPLATE = 0x10,
	MCE_ARI_MCA_RD_WR_SECURE_ACCESS_REGISTER = 0x11,
	MCE_ARI_MCA_RD_WR_GLOBAL_CONFIG_REGISTER = 0x12,
} dmce_ari_mca_read_indexes_t;

typedef enum {
	MCE_ARI_MCA_RD_WR_ASERRX_CTRL = 0,
	MCE_ARI_MCA_RD_WR_ASERRX_STATUS = 1,
	MCE_ARI_MCA_RD_WR_ASERRX_ADDR = 2,
	MCE_ARI_MCA_RD_WR_ASERRX_MISC1 = 3,
	MCE_ARI_MCA_RD_WR_ASERRX_MISC2 = 4,
} dmce_ari_mca_read_asserx_subindexes_t;

typedef enum {
	MCE_ARI_ENUM_MASK_LSB_MSB( MCE_ARI_MCA_SECURE_REGISTER_SETTING_ENABLES_NS_PERMITTED, 0, 0),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_SECURE_REGISTER_READING_STATUS_NS_PERMITTED, 1, 1),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_SECURE_REGISTER_PENDING_MCA_ERRORS_NS_PERMITTED, 2, 2),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_SECURE_REGISTER_CLEARING_MCA_INTERRUPTS_NS_PERMITTED, 3, 3),
} dmce_ari_mca_secure_register_bitmasks_t;

typedef enum {
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_SERR_ERR_CODE, 0, 15),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_MSI_ERR, 16, 16),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_IHI_ERR, 17, 17),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_CRI_ERR, 18, 18),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_MMCRAB_ERR, 19, 19),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_CSI_ERR, 20, 20),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_RD_WR_N, 21, 21),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_REQ_ERRT, 22, 23),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_RESP_ERRT, 24, 25),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_AV, 58, 58),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_MV, 59, 59),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_EN, 60, 60),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_UC, 61, 61),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_OVF, 62, 62),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_VAL, 63, 63),

	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_AXI_ID, 0, 7),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_CQX_ID, 8, 27),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_CQX_CID, 28, 31),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_STAT_CQX_CMD, 32, 35),

	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_CTRL_EN_MSI_ERR, 0, 0),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_CTRL_EN_IHI_ERR, 1, 1),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_CTRL_EN_CRI_ERR, 2, 2),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_CTRL_EN_MMCRAB_ERR, 3, 3),
	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_CTRL_EN_CSI_ERR, 4, 4),

	MCE_ARI_ENUM_MASK_LSB_MSB(MCE_ARI_MCA_IOB_MISC_ADDR, 0, 41),
} dmce_ari_mca_iob_bitmasks_t;

#undef MCE_ARI_MASK_FROM_LSB_MSB

#endif // MTS_MCE_ARI_H
