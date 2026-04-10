domino1 = input()
domino2 = input()

left1 = domino1.find('|')
right1 = len(domino1) - left1 - 1
left2 = domino2.find('|')
right2 = len(domino2) - left2 - 1

print("Yes" if left1 == left2 or left1== right2 or right1 == left2 or right1 == right2 else "No")