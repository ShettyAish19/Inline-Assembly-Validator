; ModuleID = 'testcases/test_good.c'
source_filename = "testcases/test_good.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  store i32 10, ptr %2, align 4
  store i32 20, ptr %3, align 4
  call void asm sideeffect "movl %eax, %ebx", "~{dirflag},~{fpsr},~{flags}"() #1, !srcloc !6
  call void asm sideeffect "addl %eax, %ebx", "~{dirflag},~{fpsr},~{flags}"() #1, !srcloc !7
  %4 = load i32, ptr %2, align 4
  call void asm sideeffect "subl $0, %eax", "r,~{dirflag},~{fpsr},~{flags}"(i32 %4) #1, !srcloc !8
  call void asm sideeffect "push %rax", "~{dirflag},~{fpsr},~{flags}"() #1, !srcloc !9
  call void asm sideeffect "pop %rbx", "~{dirflag},~{fpsr},~{flags}"() #1, !srcloc !10
  call void asm sideeffect "ret", "~{dirflag},~{fpsr},~{flags}"() #1, !srcloc !11
  ret i32 0
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 18.1.3 (1ubuntu1)"}
!6 = !{i64 117}
!7 = !{i64 221}
!8 = !{i64 315}
!9 = !{i64 421}
!10 = !{i64 516}
!11 = !{i64 608}
