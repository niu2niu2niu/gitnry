import sys

obj_n = 0
p_line_a = '['
p_line_b = '['
for line in sys.stdin:
    line = line.strip()
    if line[0] == '#':
        if 'objectives = 1' in line:
            obj_n = 1
        elif 'objectives = 2' in line:
            obj_n = 2
        else:
            pass
        continue
    ctx_l = line.split('\t')
    if obj_n == 1:
        p_line_a += ctx_l[0] + ','
    elif obj_n == 2:
        p_line_a += ctx_l[0] + ','
        p_line_b += ctx_l[1] + ','
    else:
        pass

if obj_n == 1:
    print "%s]" %(p_line_a.strip(','))
elif obj_n == 2:
    print "%s]" %(p_line_a.strip(','))
    print "%s]" %(p_line_b.strip(','))
else:
    pass
