data <- read.csv("priorityQueue_vs_heap.csv", header=TRUE)
color <- rainbow(130, start = 0.4, end = 1)
plot(data$PQ, type="p", xaxt = "n", col=color, ann=FALSE, pch = 16, cex = .2)
compl <- loess(data$PQ~data$SEARCHES)
lines(data$SEARCHES, predict(compl), col = "red", lwd = 10)

axis(1, at=1:10000, data$SEARCHES)
box()


lines(data$HP, type="o", col="blue")

title(main="Priority Queue vs Heap", col.main="blue", font.main=4)
title(xlab="Itens", col.lab=rgb(0,0.5,0))
title(ylab="Comparações", col.lab=rgb(0,0.5,0))

legend(1, 6000, c("PriorityQueue","Heap"), lty=c(1,1), lwd=c(2.5,2.5),col=c("red","blue"))