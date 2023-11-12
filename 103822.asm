in_ r1
mov r2,r1
eq_ r2,.0
eq_ r1,.-
jnz r1,%m
jnz r2,%z
out .+
end
@m
out .-
end
@z
out .0
