data <- read.csv("priorityQueue_vs_heap.csv", header=TRUE)

plot(data$PQ, type="o", xaxt = "n", col="red", ann=FALSE)

axis(1, at=1:50, data$SEARCHES)
box()

lines(data$HP, type="o", col="blue")

title(main="Priority Queue vs Heap", col.main="blue", font.main=4)
title(xlab="Valores buscados", col.lab=rgb(0,0.5,0))
title(ylab="Comparações", col.lab=rgb(0,0.5,0))

legend(1, 20, c("PriorityQueue","Heap"), lty=c(1,1), lwd=c(2.5,2.5),col=c("red","blue"))