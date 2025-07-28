
/*********************************INCLUDES ***************************************************** */
/**************************************************************************************************** */
#include <iostream>
using namespace std;

/*********************************DEFINITIONS***************************************************** */
/**************************************************************************************************** */
#define LOG(X)  std::cout<<X <<endl;
#define LOG_LEVEL_ERR  0
#define LOG_LEVEL_WAR 1
#define LOG_LEVEL_INFO 2
/*********************************CLASSES***************************************************** */
/**************************************************************************************************** */
class logger
{
private:
 int m_log_level = LOG_LEVEL_ERR;
public:
  void set_log_level(int log_lvl)
  {
    m_log_level = log_lvl;
  }
  void log_war(char* msg)
  {
    if(m_log_level>= LOG_LEVEL_WAR)
    {
      std::cout<<"[error msg]"<< msg<<endl;
    }
  }
  void log_err(char* msg)
  {
    if(m_log_level>= LOG_LEVEL_ERR)
    {
      std::cout<<"[error msg]"<< msg<<endl;
    }
  }
  void log_info(char* msg)
  {
    if(m_log_level>= LOG_LEVEL_INFO)
    {
      std::cout<<"[info msg]"<< msg<<endl;
    }
  }

};
/*********************************FUNCTIONS***************************************************** */
/**************************************************************************************************** */
int main()
{
    logger log;
    log.set_log_level(LOG_LEVEL_INFO);
    log.log_err("This is an error message.");
    log.log_info("This is an INFO message.");
    log.log_war("This is an war message.");

    /*won't be printed as level is err and log is info*/
    log.set_log_level(LOG_LEVEL_ERR);

    log.log_info("This is an INFO message.");


    return 0;
}