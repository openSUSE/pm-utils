#include <libhal.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	LibHalContext *ctx;
	char **devs;
	DBusError error;
	DBusConnection *conn;
	int num, x, rc = 255;
	
	ctx = libhal_ctx_new();
	if (!ctx) {
		return 255;
	}
	dbus_error_init(&error);
	conn = dbus_bus_get (DBUS_BUS_SYSTEM, &error);
	if (!conn) {
		return 255;
	}
	if (!libhal_ctx_set_dbus_connection(ctx, conn)) {
		return 255;
	}
	if (!libhal_ctx_init(ctx,&error)) {
		return 255;
	}
	/* Check for AC/DC/etc adapters */
	devs = libhal_find_device_by_capability(ctx, "ac_adapter", &num, &error);;
	if (num) {
		for (x = 0; x < num ; x++) {
			dbus_bool_t is_present;
			
			is_present = libhal_device_get_property_bool(ctx, devs[x], "ac_adapter.present", &error);
			if (!dbus_error_is_set(&error) && is_present) {
				rc = 0;
				goto out;
			}
		}
	}
	/* If there are none, check for batteries. If there are no
	   batteries either, assume AC. */
	devs = libhal_find_device_by_capability(ctx, "battery", &num, &error);;
	if (num) {
		rc = 1;
	} else {
		rc = 0;
	}
out:
	libhal_ctx_shutdown (ctx, &error);
	libhal_ctx_free (ctx);
	dbus_connection_disconnect (conn);
	return rc;
}
