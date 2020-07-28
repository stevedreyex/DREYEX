from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time


#https://medium.com/@brettlin_78528/%E7%94%A8-python-%E5%8C%AF%E5%85%A5-selenium-%E7%9A%84%E6%96%B9%E5%BC%8F-%E4%BB%A5%E5%8F%8A%E5%A6%82%E4%BD%95%E7%94%A8mac-%E5%AE%89%E8%A3%9D-chromedriver-5d92121c02d7
chromedriver = '/usr/local/bin/chromedriver'
driver = webdriver.Chrome(chromedriver)

driver.set_window_size("1200", "800")
driver.implicitly_wait(10)

url = "http://my.utaipei.edu.tw/utaipei/index_sky.html"
driver.get(url)
driver.switch_to.frame('loginFrame')
elem_user = driver.find_element_by_class_name('texttwo')
elem_user.send_keys("U10709011")
elem_pwd = driver.find_element_by_class_name('textone')
elem_pwd.send_keys("8888")
elem_pwd.send_keys(Keys.RETURN)
time.sleep(5)
driver.quit()