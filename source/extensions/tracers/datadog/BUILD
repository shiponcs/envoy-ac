load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_extension",
    "envoy_cc_library",
    "envoy_extension_package",
)

licenses(["notice"])  # Apache 2

# Trace driver for Datadog (https://datadoghq.com/)

envoy_extension_package()

envoy_cc_library(
    name = "datadog_tracer_lib",
    srcs = [
        "agent_http_client.cc",
        "datadog_tracer_impl.cc",
        "dict_util.cc",
        "event_scheduler.cc",
        "logger.cc",
        "span.cc",
        "time_util.cc",
        "tracer.cc",
    ],
    hdrs = [
        "agent_http_client.h",
        "datadog_tracer_impl.h",
        "dict_util.h",
        "event_scheduler.h",
        "logger.h",
        "span.h",
        "time_util.h",
        "tracer.h",
        "tracer_stats.h",
    ],
    copts = [
        # Make sure that headers included from dd_trace_cpp use Abseil
        # equivalents of std::string_view and std::optional.
        "-DDD_USE_ABSEIL_FOR_ENVOY",
    ],
    external_deps = [
        "dd_trace_cpp",
        "dd_opentracing_cpp",
    ],
    deps = [
        "//source/common/config:utility_lib",
        "//source/common/http:async_client_utility_lib",
        "//source/common/upstream:cluster_update_tracker_lib",
        "//source/common/version:version_lib",
        "//source/extensions/tracers/common/ot:opentracing_driver_lib",
        "@envoy_api//envoy/config/trace/v3:pkg_cc_proto",
    ],
)

envoy_cc_extension(
    name = "config",
    srcs = ["config.cc"],
    hdrs = ["config.h"],
    deps = [
        ":datadog_tracer_lib",
        "//source/extensions/tracers/common:factory_base_lib",
        "@envoy_api//envoy/config/trace/v3:pkg_cc_proto",
    ],
)
