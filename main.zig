const std = @import("std");
const assert = std.debug.assert;

const Tag = struct {
    v1: u32,
    v2: u32,
    v3: u32,
    buff: [64]u8,
};

pub fn main() !void {
    std.debug.print("This is zig\n", .{});
    //var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    //defer assert(gpa.detectLeaks() == false);
    //var allocator = gpa.allocator();

    // var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    //defer arena.deinit();
    // var allocator = arena.allocator();

    var allocator = std.heap.c_allocator;

    const args = try std.process.argsAlloc(allocator);
    defer std.process.argsFree(allocator, args);

    var COUNT_2 = try std.fmt.parseInt(u32, args[1], 10);

    var LOOP_TIMES = try std.fmt.parseInt(u32, args[2], 10);
    var v1_arr_to_find = [_]u32{
        COUNT_2 / 2,
        COUNT_2 / 2 + COUNT_2 / 6,
        COUNT_2 / 2 + COUNT_2 / 5,
        COUNT_2 / 2 + COUNT_2 / 4,
        COUNT_2 / 2 + COUNT_2 / 3,
    };

    var v = std.MultiArrayList(Tag){};
    defer v.deinit(allocator);

    try v.ensureTotalCapacity(allocator, COUNT_2);

    // push
    for (0..COUNT_2) |i_u64| {
        var i: u32 = @intCast(i_u64);
        var i_mul: u8 = @intCast(i % 200);
        v.appendAssumeCapacity(.{
            .v1 = i,
            .v2 = i + 1,
            .v3 = i + 2,
            .buff = [_]u8{i_mul} ** 64,
        });
    }

    // find
    var sum: u64 = 0;
    for (0..LOOP_TIMES) |_| {
        for (v1_arr_to_find) |v1_to_find| {
            for (v.items(.v1), 0..) |v1, i| {
                if (v1 == v1_to_find) {
                    var t = &v.get(i);
                    sum += t.v2 + t.v3;
                    for (t.buff) |b| {
                        sum += b;
                    }
                }
            }
        }
    }

    std.debug.print("sum: {}\n", .{sum});
}
