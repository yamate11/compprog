x, y = map(int, input().split())
print(min([ py - px + ex + ey
            for px, ex in [(x, 0), (-x, 1)]
            for py, ey in [(y, 0), (-y, 1)]
            if px <= py ]))
