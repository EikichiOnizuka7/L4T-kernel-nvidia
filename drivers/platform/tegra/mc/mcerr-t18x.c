/*
 * Tegra 12x SoC-specific mcerr code.
 *
 * Copyright (c) 2014, NVIDIA Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <linux/platform/tegra/mcerr.h>
#include <dt-bindings/memory/tegra-swgroup.h>

/*
 * Dummy data types - not yet sure the details on t18x mcerr yet.
 */
struct mc_client mc_clients[] = {
	dummy_client,
};
int mc_client_last = ARRAY_SIZE(mc_clients) - 1;

void mcerr_chip_specific_setup(struct mcerr_chip_specific *spec)
{
	spec->nr_clients = ARRAY_SIZE(mc_clients);
	return;
}
