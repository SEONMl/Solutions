def init(color, ball):
	for _ in range(len(ball)):
		c = ball.pop()
		if c != color :
			ball.append(c)
			break
	return ball
def move(color, ball):
	ball = init(color, ball)
	return ball.count(color)
N = int(input())
ball = list(input())
print(min(move('R',ball[:]), move('R',ball[::-1]), move('B',ball[:]), move('B',ball[::-1])))