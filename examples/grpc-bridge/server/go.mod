module github.com/envoyproxy/envoy

go 1.13

require (
	github.com/envoyproxy/envoy/examples/grpc-bridge/server v0.0.0-20240109085715-b0317d2f0b74
	golang.org/x/net v0.20.0
	google.golang.org/grpc v1.60.1
)

replace github.com/envoyproxy/envoy/examples/grpc-bridge/server/kv => ./kv
