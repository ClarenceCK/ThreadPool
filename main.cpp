//#include <iostream>
//
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//int main(int argc, char** argv) {
//	return 0;
//}

#include <iostream>
#include <chrono>
#include <condition_variable>
#include "ThreadPool.h"

/*int g_sum = 0;

std::mutex g_mutex;
std::condition_variable g_cond;

void testfun()
{

printf("testfun() wait\n" );
  std::unique_lock<std::mutex> g_lock(g_mutex);
  g_cond.wait(g_lock);

  printf("testfun exit\n");
}

void testfun2()
{

printf("testfun2 wait\n" );
  std::unique_lock<std::mutex> g_lock(g_mutex);
  g_cond.wait_for(g_lock, std::chrono::milliseconds(3500));

  printf("testfun2 exit\n");
}


int main()
{
  Thread t(testfun);
  t.start();
  Thread t2(testfun2);
  t2.start();

  printf("%d\n", t.getThreadId());

  getchar();

  printf("notify testfun\n");
  g_cond.notify_one();

  getchar();
}*/
/*
std::mutex g_mutex;

int main()
{
  Condition cond(g_mutex);

  cond.waitForSeconds(3.1658);

  printf("main exit\n");

  return 0;
}
*/
/*
int main()
{
  {
  ThreadPool threadPool;
  threadPool.start();

  getchar();
  }

  getchar();

  return 0;
}

*/

std::mutex g_mutex;

void priorityFunc()
{
  for (int i = 1; i < 4; ++i)
  {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::lock_guard<std::mutex> lock(g_mutex);
      std::cout << "priorityFunc() [" << i << "] at thread [ " << std::this_thread::get_id() << "] output" << std::endl;
  }

}

void testFunc()
{
  // loop to print character after a random period of time
  for (int i = 1; i < 4; ++i)
  {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::lock_guard<std::mutex> lock(g_mutex);
      std::cout << "testFunc() [" << i << "] at thread [ " << std::this_thread::get_id() << "] output" << std::endl;
  }

}


int main()
{
  sola::active_logger = std::unique_ptr<sola::logger>(new sola::logger(sola::logger::log_level::debug));

  sola::ThreadPool ThreadPool;

  for(int i = 0; i < 5 ; i++)
    ThreadPool.add_task(testFunc);

  getchar();
  return 0;
}
