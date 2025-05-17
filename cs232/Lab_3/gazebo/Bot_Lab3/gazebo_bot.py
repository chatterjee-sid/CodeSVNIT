import rospy
from geometry_msgs.msg import Twist
class ControlRobot:
	def __init__(self):
		rospy.init_node('ControlRobot', anonymous=True)
		self.cmd_vel = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
		rate = rospy.Rate(10)
		move_cmd = Twist()
		move_cmd.linear.x = 0.5
		while not rospy.is_shutdown():
			self.cmd_vel.publish(move_cmd)
			rate.sleep()

if __name__ == '__main__':
	try:
		ControlRobot()
	except rospy.ROSInterruptException:
		pass
