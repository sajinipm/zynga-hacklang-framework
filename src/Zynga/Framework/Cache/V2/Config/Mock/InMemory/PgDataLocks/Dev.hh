<?hh // strict

namespace Zynga\Framework\Cache\V2\Config\Mock\InMemory\PgDataLocks;

use Zynga\Framework\Cache\V2\Config\Mock\InMemory\PgDataBase;
use Zynga\Framework\Cache\V2\Exceptions\InvalidObjectForKeyCreationException;
use Zynga\Framework\PgData\V1\Interfaces\PgRowInterface;
use Zynga\Framework\StorableObject\V1\Interfaces\StorableObjectInterface;

use \Exception;

class Dev extends PgDataBase {

  public function createKeyFromStorableObject(
    StorableObjectInterface $obj,
  ): string {

    if ($obj instanceof PgRowInterface) {

      $pk = strval($obj->getPrimaryKeyTyped()->get());
      $key = 'pg:'.md5(get_class($obj)).':'.$pk.':lock';
      return $key;

    }

    throw new InvalidObjectForKeyCreationException(
      'PgDataTest only supports pgData objects.',
    );

  }

  public function getTTL(): int {
    return 30;
  }

}
