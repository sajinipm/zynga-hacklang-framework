<?hh // strict

namespace Zynga\Framework\ShardedDatabase\V3\Driver\GenericPDO;

use Zynga\Framework\Exception\V1\Exception;

use Zynga\Framework\ShardedDatabase\V3\Interfaces\TransactionInterface;
use Zynga\Framework\ShardedDatabase\V3\Interfaces\DriverInterface;

class Transaction implements TransactionInterface {
  private DriverInterface $_dbh;

  public function __construct(DriverInterface $driver) {
    $this->_dbh = $driver;
  }

  public function begin(): bool {
    try {
      $this->_dbh->query('START TRANSACTION');
      return true;
    } catch (Exception $e) {
      throw $e;
    }
  }

  public function commit(): bool {
    try {
      $this->_dbh->query('COMMIT');
      return true;
    } catch (Exception $e) {
      throw $e;
    }
  }

  public function rollback(): bool {
    try {
      $this->_dbh->query('ROLLBACK');
      return true;
    } catch (Exception $e) {
      throw $e;
    }
  }

}
