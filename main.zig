const std = @import("std");
const assert = std.debug.assert;
const c = @cImport({
    @cInclude("config.h");
});

const Tag = struct {
    v1: u32,
    v2: u32,
    v3: u32,
    v4: u64,
};

fn tag_init(tag: *Tag, i: u32) void {
    tag.v1 = i * 2;
    tag.v2 = i * 3;
    tag.v3 = i * 4;
}

fn tag_same(tag1: Tag, tag2: Tag) bool {
    if (tag1.v1 != tag2.v1) {
        return false;
    }
    if (tag1.v2 != tag2.v2) {
        return false;
    }
    if (tag1.v3 != tag2.v3) {
        return false;
    }
    return true;
}

pub fn main() !void {
    std.debug.print("This is zig\n", .{});
    //var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    //defer assert(gpa.detectLeaks() == false);
    //var allocator = gpa.allocator();

    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    //defer arena.deinit();
    var allocator = arena.allocator();

    //var allocator = std.heap.page_allocator;

    var v = try std.ArrayList(Tag).initCapacity(allocator, c.COUNT);
    defer v.deinit();

    // push
    for (0..c.COUNT) |i| {
        var t: Tag = undefined;
        tag_init(&t, @intCast(i));
        v.appendAssumeCapacity(t);
    }

    // find
    var tag_to_find: Tag = undefined;
    tag_init(&tag_to_find, c.COUNT / 2);
    for (v.allocatedSlice()) |t| {
        if (tag_same(tag_to_find, t)) {
            std.debug.print("We found it\n", .{});
        }
    }
}
